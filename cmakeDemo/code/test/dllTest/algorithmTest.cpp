#include "algorithmTest.h"

using namespace ns_algorithm_test;

void AlgorithmTest::init()
{
	algorithmPtr = shared_ptr<Algorithm>(new Algorithm);
};

void AlgorithmTest::testExecute()
{
	cout << "-----------------------------------------\t algorithm 测试开始 \t\t---------------------------------" << endl;

	//加法
	addInt();
	addFloat();

	//减法
	subInt();
	subFloat();

	cout << "-----------------------------------------\t algorithm 测试结束 \t\t---------------------------------" << endl;
	cout << endl;
}

void AlgorithmTest::addInt()
{
	int32_t a = 10;
	int32_t b = 20;
	int32_t res = algorithmPtr->add(a, b);
	cout << " 算法测试：  add(int)执行情况: " << " 入参a为" << a << "; 入参b为" << b << "; 结果为" << res << endl;
}

void AlgorithmTest::addFloat()
{
	float a = 1.1;
	float b = 1.2;
	float res = algorithmPtr->add(a, b);
	cout << " 算法测试： add(float)执行情况: " << " 入参a为" << a << "; 入参b为" << b << "; 结果为" << res << endl;
}

void AlgorithmTest::subInt()
{
	int32_t a = 10;
	int32_t b = 20;

	int32_t res = algorithmPtr->sub(a, b);
	cout << " 算法测试：  sub(int)执行情况: " << " 入参a为" << a << "; 入参b为" << b << "; 结果为" << res << endl;
}

void AlgorithmTest::subFloat()
{
	float a = 1.1;
	float b = 1.2;
	float res = algorithmPtr->sub(a, b);
	cout << " 算法测试：  sub(float)执行情况: " << " 入参a为" << a << "; 入参b为" << b << "; 结果为" << res << endl;
}



