#include "threadTest.h"

using namespace ns_thread_test;
using namespace ns_my_thread_pool_test;


bool ThreadTest::gNumIsNotZero()
{
	return g_num != 0;
}

void ThreadTest::consumeThread(int cycle)
{
	for (int32_t i = 0; i < cycle; ++i)
	{
		//�����Ӳ��� std::defer_lock����Ĭ�ϲ����������������� m_unique_lock.lock();
		//��std::lock( m_unique_lock , m_unique_lock2...)�϶����
		std::unique_lock<std::mutex> m_unique_lock(m_mutex);

	    //��ʽ1: ʹ��lamda���ʽ ,  ����Ϊfalse��g_num = 0��ʱ������
		//m_condition.wait(m_unique_lock, [&]() {return g_num != 0; }); 

		//��ʽ2 gNumIsNotZero����Ϊfalse��g_num = 0��ʱ������
		while (!gNumIsNotZero())
		{
			m_condition.wait(m_unique_lock);
		}

		std::cout << "  g_num = " << g_num << std::endl;
		g_num = 0;
	}
}

void ThreadTest::conditionMainThread(int cycle)
{
	std::cout << "�����������Կ�ʼ " << std::endl;
	std::thread m_thread(&ThreadTest::consumeThread,this,cycle);

	//condition_variable���ֽ�� unique_lockʹ��; condition_variable_any���Ժ�������ʹ��
	for (int32_t i = 0; i < cycle; ++i)
	{
		//g_num��Ϊ0ʱ����ǰ�̹߳���
		while (gNumIsNotZero())
		{
			std::this_thread::yield();
		}

		std::unique_lock<std::mutex> m_unique_lock(m_mutex);
		g_num = i + 1;
	
		//���ѵ�ǰ�������߳�. ���ж�����������. notify_all�ɻ��������߳�
		m_condition.notify_one();
	}
	
	m_thread.join();
	std::cout << "�����������Խ��� " << std::endl;
}

void ThreadTest::getVector()
{
	std::cout << "m_vec����Ϊ: " << std::endl;
	for (int32_t i = 0; i < m_vec.size(); ++i)
	{
		std::cout << m_vec[i] << " ";
	}
	std::cout<< std::endl;
}

void ThreadTest::threadFuncDemo1()
{
	int threadId = *(unsigned int*)&std::this_thread::get_id();
	//������ʽ 1 -lock
	{
		m_mutex.lock();
		m_vec.push_back(1);
		std::cout << "  func threadFuncDemo1 sub thread id is: " << std::this_thread::get_id() << std::endl;	
		std::cout << "  func threadFuncDemo1 execute end - index 1" << std::endl;
		m_mutex.unlock();
	}
	//������ʽ 2 -lock_guard
	{
		std::lock_guard<std::mutex> m_lock_guard(m_mutex);
		m_vec.push_back(2);
		std::cout << "  func threadFuncDemo1 execute end - index 2" << std::endl;
	}
}

void ThreadTest::threadFuncDemo2(int a)
{
	int threadId = *(unsigned int*)&std::this_thread::get_id();
	//������ʽ 1 -lock
	{
		m_mutex.lock();
		std::cout << "  func threadFuncDemo2 sub thread id is: " << std::this_thread::get_id() << std::endl;
		std::cout << "  func threadFuncDemo2 param = " << a << std::endl;
		m_vec.push_back(3);
		std::cout << "  func threadFuncDemo2 execute end - index 1" << std::endl;
		m_mutex.unlock();
	}

	//������ʽ 2 -lock_guard
	{
		std::lock_guard<std::mutex> m_lock_guard(m_mutex);
		m_vec.push_back(4);
		std::cout << "  func threadFuncDemo2 execute end - index 2" << std::endl;
	}
}

void ThreadTest::simpleThreadCreate()
{
	std::cout << "���������߳� ��ʼ  " << std::endl;
	//�߳�1 �������Ա������ע���÷�������ʡ����������
	std::cout << "  start create thread 1 " << std::endl;
	std::thread m_thread1(&ThreadTest::threadFuncDemo1,this);

	
	//�߳�2 �������Ա������ע���÷�������ʡ����������
	std::cout << "  start create thread 2 " << std::endl;
	std::thread m_thread2(&ThreadTest::threadFuncDemo2, this, 10);

	//m_thread2.detach();ʹ��detach�����̲߳���ȴ����߳�ִ�н��������߳�ִ���꣬��������

	m_thread1.join();//����
	m_thread2.join();

	getVector();
	std::cout << "���������߳� ����  " << std::endl;
}

void ThreadTest::threadPoolV1Test(int num)
{
	std::cout << "�̳߳ز��� ��ʼ  " << std::endl;

	ThreadPoolV1<TestTaskV1> threadPool(num);
	for (int i = 0; i < 10; ++i) 
	{
		TestTaskV1* tTask = new TestTaskV1();
		threadPool.append(tTask);
		delete tTask;
	}
	std::cout << "�̳߳ز��� ����  " << std::endl;
}

void taskFunc(void* arg)
{
	int nNum = *(int*)arg;
	cout << "thread: " << std::this_thread::get_id() << ", number=" << nNum << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ThreadTest::threadPoolV2Test()
{
	ThreadPoolV2 pool(5, 10);
	int i;
	// ��������������100������
	for (i = 0; i < 100; ++i)
	{
		int* pNum = new int(i + 100);
		pool.Add(taskFunc, (void*)pNum);
	}
	for (; i < 200; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		int* pNum = new int(i + 100);
		pool.Add(taskFunc, (void*)pNum);
	}
}

void ThreadTest::threadPoolV3Test()
{
	ThreadPoolV3ByHandWrite pool(5, 10);
	int i;
	// ��������������50������
	for (i = 0; i < 50; ++i)
	{
		int* pNum = new int(i + 100);
		pool.appendTask(taskFunc, (void*)pNum);
	}
	for (; i < 70; ++i)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		int* pNum = new int(i + 100);
		pool.appendTask(taskFunc, (void*)pNum);
	}
}

void ThreadTest::testExecute()
{
	cout << "-----------------------------------------\t thread ���Կ�ʼ \t\t---------------------------------" << endl;

	std::cout << "main thread id is: " << std::this_thread::get_id() << std::endl;

	//���ô����̷߳���
	//simpleThreadCreate();

	//condition������������
	//conditionMainThread(10);

	threadPoolV1Test(2);
	//threadPoolV2Test();
	//threadPoolV3Test();

	cout << "-----------------------------------------\t thread ���Խ��� \t\t---------------------------------" << endl;
	cout << endl;
}