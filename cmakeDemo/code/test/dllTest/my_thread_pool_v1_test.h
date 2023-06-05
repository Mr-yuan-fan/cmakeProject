#ifndef __THREAD_POOL_TEST_H__
#define __THREAD_POOL_TEST_H__

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <stdexcept>
#include <queue>
#include<assert.h>

#include "dll//common/common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_my_thread_pool_test)

#define MAX_THREAD_NUM 100

class TestTask
{
public:
	void process()
	{
		cout << "process.........thread id = " <<this_thread::get_id()<< endl;
		//������������
		long i = 1000;
		while (i != 0)
		{
			int j = sqrt(i);
			i--;
		}
	}
};


template <typename T>
class ThreadPoolV1
{
public:
	ThreadPoolV1(int number = 1);//Ĭ�Ͽ�һ���߳�
	~ThreadPoolV1();
	std::queue<T *> tasks_queue;		   //�������

	bool append(T *request);//��������У�task_queue�����������<T *>

private:
	//�����߳���Ҫ���еĺ���,���ϵĴ����������ȡ����ִ��
	static void *worker(void *arg);
	void run();

private:
	std::vector<std::thread> work_threads; //�����߳�

	std::mutex queue_mutex;
	std::condition_variable condition;  //������unique_lock���ʹ��
	bool stop;

};//end class

//���캯���������߳�
template <typename T>
ThreadPoolV1<T>::ThreadPoolV1(int number):stop(false)
{
	if (number <= 0 || number > MAX_THREAD_NUM)
		throw std::exception();
	for (int i = 0; i < number; i++)
	{
		std::cout << "created Thread num is : " << i << std::endl;
		work_threads.emplace_back(worker, this);//����߳�
		//ֱ��������β���������Ԫ�أ�ʡȥ�˿������ƶ�Ԫ�صĹ��̡�
	}
}

template <typename T>
inline ThreadPoolV1<T>::~ThreadPoolV1()
{

	std::unique_lock<std::mutex> lock(queue_mutex);
	stop = true;
	condition.notify_all();
	for (auto &ww : work_threads)
		ww.join();//����������������join
}

//�������
template <typename T>
bool ThreadPoolV1<T>::append(T *request)
{
	/*������������ʱһ��Ҫ��������Ϊ���������̹߳���*/
	queue_mutex.lock();//ͬһ�������
	tasks_queue.push(request);
	queue_mutex.unlock();
	condition.notify_one(); //�̳߳���ӽ�ȥ��������ȻҪ֪ͨ�ȴ����߳�
	return true;
}

//�����߳�
template <typename T>
void *ThreadPoolV1<T>::worker(void *arg)
{
	ThreadPoolV1 *pool = (ThreadPoolV1 *)arg;
	pool->run();//�߳�����
	return pool;
}

template <typename T>
void ThreadPoolV1<T>::run()
{
	
	while (!stop)
	{
		std::unique_lock<std::mutex> lk(this->queue_mutex);
		std::cout << "run thread id = : " << this_thread::get_id() << std::endl;
		/*��unique_lock() ����������Զ�������*/
		this->condition.wait(lk, [this] { return !this->tasks_queue.empty(); });
		//�������Ϊ�գ���wait����ͣ�����ȴ�����
		//��Ҫ�����񣬲��������̣߳���Ȼ������
		if (this->tasks_queue.empty())//����Ϊ�գ�˫�ر���
		{
			assert(0 && "����");//ʵ���ϲ������е���һ������Ϊ����Ϊ�գ�wait�������ˡ�
			continue;
		}
		else
		{
			T *request = tasks_queue.front();
			tasks_queue.pop();
			if (request)//�������ˣ���ʼִ��
				request->process();
		}
	}
}


ENDNAMESPACE

#endif