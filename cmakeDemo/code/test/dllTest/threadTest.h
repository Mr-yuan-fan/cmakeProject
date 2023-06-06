#ifndef __THREAD_TEST_H_
#define __THREAD_TEST_H_

#include "dll/common/common_utitly.h"
#include "my_thread_pool_v1_test.h"
#include "my_thread_pool_v2_test.h"
#include "my_thread_pool_v3_handwrite_test.h"

#include <thread>
#include <windows.h>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace ns_my_thread_pool_test;

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

	//�ڲ���������

	void simpleThreadCreate();

	void conditionMainThread(int cycle);

	bool gNumIsNotZero();

	void threadPoolV1Test(int num);

	void threadPoolV2Test();

	void threadPoolV3Test();

private:
	
	//�̺߳���

	void ThreadTest::threadFuncDemo1();

	void ThreadTest::threadFuncDemo2(int a);

	void consumeThread(int cycle);

private:

	std::mutex m_mutex;
	std::condition_variable m_condition;

	std::vector<int> m_vec;
	int g_num = 0;
};

typedef shared_ptr<ThreadTest>  ThreadTestPtr;

ENDNAMESPACE
#endif