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
	//开启管理线程
	managerThread = thread(manager, this);
	threadVec.resize(max);
	for (int32_t i = 0; i < min; ++i)
	{
		//开启工作线程
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
		//3秒查询一次工作线程状态
		this_thread::sleep_for(chrono::seconds(3));

		unique_lock<mutex> lk(pool->m_mutex);

		int queueSize = pool->taskQ.size();
		int liveNum = pool->liveNum;
		int busyNum = pool->busyNum;
		int maxNum = pool->maxNum;
		int minNum = pool->minNum;
		//任务繁忙，需要增加线程
		if (queueSize > liveNum && liveNum < maxNum)
		{
			int count = 0;
			for (int32_t i = 0; i < maxNum &&  count < 2 &&  liveNum < maxNum; ++i)
			{
				//当前线程为空，则增加线程
				if (pool->threadVec[i].get_id() == thread::id())
				{
					cout << "manager -- create a new thread..." << endl;
					pool->threadVec[i] = thread(worker, pool);
					++pool->liveNum;
					++count;
				}
			}
		}

		//忙活线程较少，则通知2个工作线程自我销毁
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
		//若任务为空 且 线程池未停止，则阻塞等待
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

		// 判断线程池是否关闭了
		if (pool->shutdown)
		{
			cout << "worker -- threadid2: " << std::this_thread::get_id() << "exit......" << endl;
			return;
		}

		// 从任务队列中去除一个任务
		TestTask task = pool->taskQ.front();
		pool->taskQ.pop();
		pool->busyNum++;
		// 当访问完线程池队列时，线程池解锁
		lk.unlock();

		// 取出Task任务后，就可以在当前线程中执行该任务了
		cout << "thread: " << std::this_thread::get_id() << " start working..." << endl;
		task.function(task.arg);

		free(task.arg);
		task.arg = nullptr;

		// 任务执行完毕,忙线程解锁
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
	//添加任务
	taskQ.push(TestTask(func, arg));
	m_condition.notify_all();
}