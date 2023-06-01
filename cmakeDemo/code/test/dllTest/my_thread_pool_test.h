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


#include "dll//common/common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_my_thread_pool_test)

#define MAX_THREAD_NUM 100

class TestTask
{
public:
	TestTask() {};
	~TestTask() {};

public:
	void process()
	{
		cout << "this is called by thread pool " << endl;
	};
};


template<typename T>
class ThreadPool
{
public:

	ThreadPool(int num = 1);

	~ThreadPool();

public:

	void append(T* request);

private:

	static void* worker(void* arg);

	void run();


private:

	vector<thread> work_threads;//工作线程
	mutex m_mutex;
	condition_variable m_condition;
	queue<T*> m_queue;
	bool isStop;
};

template<typename T>
ThreadPool<T>::ThreadPool(int num) :isStop(false)
{
	if (num <= 0 || num > MAX_THREAD_NUM)
	{
		throw::exception();
	}
	for (int i = 0; i < num; ++i)
	{
		work_threads.emplace_back(worker, this);
	}
};

template<typename T>
ThreadPool<T>::~ThreadPool()
{
	unique_lock<mutex> m_u_lck(m_mutex);
	isStop = true;

	m_condition.notify_all();
	for (auto& iter : work_threads)
	{
		iter.join();
	}

};


template<typename T>
void ThreadPool<T>::append(T* request)
{
	m_mutex.lock();
	m_queue.push(request);
	m_mutex.unlock();
	m_condition.notify_one();
};

template<typename T>
void* ThreadPool<T>::worker(void* arg)
{
	ThreadPool* threadPoolPtr = (ThreadPool*)arg;

	threadPoolPtr->run();

	return threadPoolPtr;
};

template<typename T>
void ThreadPool<T>::run()
{
	while (!isStop)
	{
		unique_lock<mutex> m_u_lck(m_mutex);
		m_condition.wait(m_u_lck, [this] {return !m_queue.empty(); });
		cout << "thread id =  " << this_thread::get_id() << endl;

		if (!m_queue.empty())
		{
			T* request = m_queue.front();
			m_queue.pop();
			if (request)
			{
				request->process();
			}
		}
	}
}

ENDNAMESPACE

#endif