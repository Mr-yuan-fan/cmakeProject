#include "threadTest.h"

using namespace ns_thread_test;
using namespace ns_common;


bool ThreadTest::gNumIsNotZero()
{
	return g_num != 0;
}

void ThreadTest::consumeThread(int cycle)
{
	for (int32_t i = 0; i < cycle; ++i)
	{
		//若增加参数 std::defer_lock，则默认不加锁，需主动调用 m_unique_lock.lock();
		//或std::lock( m_unique_lock , m_unique_lock2...)上多个锁
		std::unique_lock<std::mutex> m_unique_lock(m_mutex);

	    //方式1: 使用lamda表达式 ,  返回为false（g_num = 0）时才阻塞
		//m_condition.wait(m_unique_lock, [&]() {return g_num != 0; }); 

		//方式2 gNumIsNotZero返回为false（g_num = 0）时才阻塞
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
	std::cout << "条件变量测试开始 " << std::endl;
	std::thread m_thread(&ThreadTest::consumeThread,this,cycle);

	//condition_variable必现结合 unique_lock使用; condition_variable_any可以和任意锁使用
	for (int32_t i = 0; i < cycle; ++i)
	{
		//g_num不为0时，当前线程挂起
		while (gNumIsNotZero())
		{
			std::this_thread::yield();
		}

		std::unique_lock<std::mutex> m_unique_lock(m_mutex);
		g_num = i + 1;
	
		//唤醒当前阻塞的线程. 若又多个，随机唤醒. notify_all可唤醒所有线程
		m_condition.notify_one();
	}
	
	m_thread.join();
	std::cout << "条件变量测试结束 = " << std::endl;
}

void ThreadTest::getVector()
{
	std::cout << "m_vec内容为: " << std::endl;
	for (int32_t i = 0; i < m_vec.size(); ++i)
	{
		std::cout << m_vec[i] << " ";
	}
	std::cout<< std::endl;
}

void ThreadTest::threadFuncDemo1()
{
	int threadId = *(unsigned int*)&std::this_thread::get_id();
	//加锁方式 1 -lock
	{
		m_mutex.lock();
		m_vec.push_back(1);
		std::cout << "  func threadFuncDemo1 sub thread id is: " << std::this_thread::get_id() << std::endl;	
		std::cout << "  func threadFuncDemo1 execute end - index 1" << std::endl;
		m_mutex.unlock();
	}
	//加锁方式 2 -lock_guard
	{
		std::lock_guard<std::mutex> m_lock_guard(m_mutex);
		m_vec.push_back(2);
		std::cout << "  func threadFuncDemo1 execute end - index 2" << std::endl;
	}
}

void ThreadTest::threadFuncDemo2(int a)
{
	int threadId = *(unsigned int*)&std::this_thread::get_id();
	//加锁方式 1 -lock
	{
		m_mutex.lock();
		std::cout << "  func threadFuncDemo2 sub thread id is: " << std::this_thread::get_id() << std::endl;
		std::cout << "  func threadFuncDemo2 param = " << a << std::endl;
		m_vec.push_back(3);
		std::cout << "  func threadFuncDemo2 execute end - index 1" << std::endl;
		m_mutex.unlock();
	}

	//加锁方式 2 -lock_guard
	{
		std::lock_guard<std::mutex> m_lock_guard(m_mutex);
		m_vec.push_back(4);
		std::cout << "  func threadFuncDemo2 execute end - index 2" << std::endl;
	}
}

void ThreadTest::simpleThreadCreate()
{
	std::cout << "创建基础线程 开始  " << std::endl;
	//线程1 调用类成员函数，注意用法，不可省略类作用域
	std::cout << "  start create thread 1 " << std::endl;
	std::thread m_thread1(&ThreadTest::threadFuncDemo1,this);

	
	//线程2 调用类成员函数，注意用法，不可省略类作用域
	std::cout << "  start create thread 2 " << std::endl;
	std::thread m_thread2(&ThreadTest::threadFuncDemo2, this, 10);

	//m_thread2.detach();使用detach，主线程不会等待子线程执行结束。主线程执行完，则程序结束

	m_thread1.join();//阻塞
	m_thread2.join();

	getVector();
	std::cout << "创建基础线程 结束  " << std::endl;
}

void ThreadTest::testExecute()
{
	cout << "-----------------------------------------\t thread 测试开始 \t\t---------------------------------" << endl;

	std::cout << "main thread id is: " << std::this_thread::get_id() << std::endl;

	//调用创建线程方法
	simpleThreadCreate();

	//condition条件变量测试
	conditionMainThread(10);

	cout << "-----------------------------------------\t thread 测试结束 \t\t---------------------------------" << endl;
	cout << endl;
}