#include "my_thread_pool_v3_handwrite_test.h"


using namespace std;
using namespace ns_my_thread_pool_test;


ThreadPoolV3ByHandWrite::ThreadPoolV3ByHandWrite(int32_t min, int32_t max)
{
	shutdown = false;

	this->minNum = min;
	this->liveNum = min;
	this->maxNum = max;
	this->deleteNum = 0;
	this->busyNum = 0;
	//���������߳�
	managerThread = thread(manager, this);
	threadVec.resize(max);
	for (int32_t i = 0; i < min; ++i)
	{
		//���������߳�
		threadVec[i] = thread(worker,this);
	}
}

ThreadPoolV3ByHandWrite::~ThreadPoolV3ByHandWrite()
{
	shutdown = true;
	if(managerThread.joinable()) managerThread.join();
	
	m_condition.notify_all();

	for (int32_t i = 0; i < threadVec.size(); ++i)
	{
		if(threadVec[i].joinable()) threadVec[i].join();
	}
}

void ThreadPoolV3ByHandWrite::manager(void* arg)
{
	ThreadPoolV3ByHandWrite* pool = static_cast<ThreadPoolV3ByHandWrite*> (arg);

	while (!pool->shutdown)
	{
		//3���ѯһ�ι����߳�״̬
		this_thread::sleep_for(chrono::seconds(3));

		unique_lock<mutex> lk(pool->m_mutex);

		int queueSize = pool->taskQ.size();
		int liveNum = pool->liveNum;
		int busyNum = pool->busyNum;
		int maxNum = pool->maxNum;
		int minNum = pool->minNum;
		//����æ����Ҫ�����߳�
		if (queueSize > liveNum && liveNum < maxNum)
		{
			int count = 0;
			for (int32_t i = 0; i < maxNum &&  count < 2 &&  liveNum < maxNum; ++i)
			{
				//��ǰ�߳�Ϊ�գ��������߳�
				if (pool->threadVec[i].get_id() == thread::id())
				{
					cout << "manager -- create a new thread..." << endl;
					pool->threadVec[i] = thread(worker, pool);
					++pool->liveNum;
					++count;
				}
			}
		}

		//æ���߳̽��٣���֪ͨ2�������߳���������
		if (busyNum * 2 < liveNum && liveNum > minNum)
		{
			pool->deleteNum = 2;
			pool->m_condition.notify_all();
		}		
	}
}

void ThreadPoolV3ByHandWrite::worker(void* arg)
{
	ThreadPoolV3ByHandWrite* pool = static_cast<ThreadPoolV3ByHandWrite*>(arg);
	while (true)
	{
		unique_lock<mutex> lk(pool->m_mutex);
		//������Ϊ�� �� �̳߳�δֹͣ���������ȴ�
		while (pool->taskQ.empty() && !pool->shutdown)
		{
			pool->m_condition.wait(lk);

			if (pool->deleteNum > 0)
			{
				pool->deleteNum--;
				if (pool->liveNum > pool->minNum)
				{
					pool->liveNum--;
					cout << " worker -- threadid1: " << std::this_thread::get_id() << " exit......" << endl;
					lk.unlock();
					return;
				}
			}
		}

		// �ж��̳߳��Ƿ�ر���
		if (pool->shutdown)
		{
			cout << "worker -- threadid2: " << std::this_thread::get_id() << "exit......" << endl;
			return;
		}

		// �����������ȥ��һ������
		TestTask task = pool->taskQ.front();
		pool->taskQ.pop();
		pool->busyNum++;
		// ���������̳߳ض���ʱ���̳߳ؽ���
		lk.unlock();

		// ȡ��Task����󣬾Ϳ����ڵ�ǰ�߳���ִ�и�������
		cout << "thread: " << std::this_thread::get_id() << " start working..." << endl;
		task.function(task.arg);

		free(task.arg);
		task.arg = nullptr;

		// ����ִ�����,æ�߳̽���
		cout << "thread: " << std::this_thread::get_id() << " end working..." << endl;
		lk.lock();
		pool->busyNum--;
		lk.unlock();
	}
}

void ThreadPoolV3ByHandWrite::appendTask(TestTask* arg)
{
	unique_lock<mutex>lk(m_mutex);
	if (shutdown)
	{
		return;
	}
	taskQ.push(*arg);
	m_condition.notify_all();
}

void ThreadPoolV3ByHandWrite::appendTask(callbackFunc func, void* arg)
{
	unique_lock<mutex> lk(m_mutex);
	if (shutdown)
	{
		return;
	}
	//�������
	taskQ.push(TestTask(func, arg));
	m_condition.notify_all();
}