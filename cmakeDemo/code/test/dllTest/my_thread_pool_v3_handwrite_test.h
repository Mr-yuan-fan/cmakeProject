#ifndef __THREAD_POOL__V3_HAND_WRITE_TEST_H__
#define __THREAD_POOL__V3_HAND_WRITE_TEST_H__

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


#include "dll//common/common_utitly.h"

using namespace std;
using namespace std::literals::chrono_literals;

BEGINENAMESPACE(ns_my_thread_pool_test)

using callbackFunc = void(*)(void *);

class TestTask
{
public:
	callbackFunc function;
	void* arg;
public:
	TestTask(callbackFunc cf, void* arg)
	{
		this->function = cf;
		this->arg = arg;
	}

};

class ThreadPoolV3ByHandWrite
{
public:
	 ThreadPoolV3ByHandWrite(int32_t min , int32_t max);
	 ~ThreadPoolV3ByHandWrite();

public:
	void appendTask(TestTask* arg);
	void appendTask(callbackFunc func, void* arg);

	static void worker(void* arg);
	static void manager(void* arg);

private:
	queue<TestTask>      taskQ;
	vector<thread>       threadVec;
	thread               managerThread;
	mutex                m_mutex;
	condition_variable   m_condition;


	int32_t         minNum;
	int32_t         maxNum;
	int32_t         liveNum;
	int32_t         deleteNum;
	int32_t         busyNum;

	bool            shutdown;
};

using namespace std;



ENDNAMESPACE
#endif