#ifndef __THREAD_TEST_H_
#define __THREAD_TEST_H_


#include "dll/common/print.h"

#include <thread>
#include <windows.h>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace ns_common;

BEGINENAMESPACE(ns_thread_test)

class ThreadTest
{
public:

	ThreadTest() 
	{

	};

	~ThreadTest() {};

public:

	void testExecute();

	void getVector();

private:

	//主调函数

	void simpleThreadCreate();

	void conditionMainThread(int cycle);

	bool gNumIsNotZero();
	
private:
	
	//线程函数

	void ThreadTest::threadFuncDemo1();

	void ThreadTest::threadFuncDemo2(int a);

	void consumeThread(int cycle);

private:

	std::mutex m_mutex;
	std::condition_variable m_condition;

	std::vector<int> m_vec;
	int g_num = 0;
};


ENDNAMESPACE
#endif