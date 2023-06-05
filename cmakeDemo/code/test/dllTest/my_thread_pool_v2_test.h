#ifndef __THREAD_POOL__V2_TEST_H__
#define __THREAD_POOL__V2_TEST_H__

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


#include "dll//common/common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_my_thread_pool_test)


using namespace std;
using namespace std::literals::chrono_literals;
using callback = void(*)(void*);

// ���������
// ��Ա�������ܣ�����1������ִ�к���������2������ִ�к����Ĳ���
class Task
{
public:
	callback function;
	void* arg;
public:
	Task(callback f, void* arg)
	{
		function = f;
		this->arg = arg;
	}
};

// �̳߳���
class ThreadPoolV2
{
public:
	ThreadPoolV2(int min, int max);
	// �������
	void Add(callback f, void* arg);
	void Add(Task task);
	// æ�̸߳���
	int Busynum();
	// ����̸߳���
	int Alivenum();
	~ThreadPoolV2();

private:
	// �������
	queue<Task> taskQ;
	thread managerID;   //�������߳�ID
	vector<thread> threadIDs;   //
	int minNum;   //��С�߳���
	int maxNum;   //����߳���
	int busyNum;   //æ���߳���
	int liveNum;    //�����߳���
	int exitNum;    //Ҫ���ٵ��߳���

	mutex mutexPool;    //�����̳߳ص���
	condition_variable cond;     //��������Ƿ�Ϊ��,�����������߳�
	bool shutdown;    //�Ƿ������̳߳أ�����Ϊ1��������Ϊ0
	static void manager(void* arg);   //�������߳�
	static void worker(void* arg);   //�����߳�
};

ENDNAMESPACE
#endif