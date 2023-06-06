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

class TestTaskV1
{
public:
	void process()
	{
		cout << "process.........thread id = " <<this_thread::get_id()<< endl;
		////������������
		//long i = 10;
		//while (i != 0)
		//{
		//	int j = sqrt(i);
		//	i--;
		//}
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
	bool getThreadPoolStatus();

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
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::unique_lock<std::mutex> lock(queue_mutex);
	stop = true;
	//һ��Ҫ���������������
	lock.unlock();

	condition.notify_all();
	for (auto &ww : work_threads)
	{
		if(ww.joinable()) ww.join();//����������������join
	}
		
}

template<class T>
bool ThreadPoolV1<T>::getThreadPoolStatus()
{
	bool res = stop;
	return res;
}


//�������
template <typename T>
bool ThreadPoolV1<T>::append(T *request)
{
	/*������������ʱһ��Ҫ��������Ϊ���������̹߳���*/
	queue_mutex.lock();//ͬһ�������
	tasks_queue.push(request);
	queue_mutex.unlock();
	condition.notify_all(); //�̳߳���ӽ�ȥ��������ȻҪ֪ͨ�ȴ����߳�
	return true;
}

//�����߳�
template <typename T>
void *ThreadPoolV1<T>::worker(void *arg)
{
	ThreadPoolV1 *pool = static_cast<ThreadPoolV1 *>(arg);
	pool->run();//�߳�����
	return pool;
}

template <typename T>
void ThreadPoolV1<T>::run()
{
	while (!stop)
	{
		std::unique_lock<std::mutex> lk(this->queue_mutex);

		//��Ҫʹ��lamda���ʽ������ʹ�õĻ���ֻ������߳�����ȥִ�ж�Ӧ�������������񲻻�ִ��
		//this->condition.wait(lk, [this] { return !this->tasks_queue.empty() && this->stop; });

		while (this->tasks_queue.empty() && !this->stop)
		{
			this->condition.wait(lk);
		}

		if (!this->tasks_queue.empty())
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