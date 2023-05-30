#include "algorithmTest.h"

using namespace ns_algorithm_test;

void AlgorithmTest::init()
{
	algorithmPtr = shared_ptr<Algorithm>(new Algorithm);
};

void AlgorithmTest::testExecute()
{
	cout << "-----------------------------------------\t algorithm ���Կ�ʼ \t\t---------------------------------" << endl;

	//�ӷ�
	addInt();
	addFloat();

	//����
	subInt();
	subFloat();

	cout << "-----------------------------------------\t algorithm ���Խ��� \t\t---------------------------------" << endl;
	cout << endl;
}

void AlgorithmTest::addInt()
{
	int32_t a = 10;
	int32_t b = 20;
	int32_t res = algorithmPtr->add(a, b);
	cout << " �㷨���ԣ�  add(int)ִ�����: " << " ���aΪ" << a << "; ���bΪ" << b << "; ���Ϊ" << res << endl;
}

void AlgorithmTest::addFloat()
{
	float a = 1.1;
	float b = 1.2;
	float res = algorithmPtr->add(a, b);
	cout << " �㷨���ԣ� add(float)ִ�����: " << " ���aΪ" << a << "; ���bΪ" << b << "; ���Ϊ" << res << endl;
}

void AlgorithmTest::subInt()
{
	int32_t a = 10;
	int32_t b = 20;

	int32_t res = algorithmPtr->sub(a, b);
	cout << " �㷨���ԣ�  sub(int)ִ�����: " << " ���aΪ" << a << "; ���bΪ" << b << "; ���Ϊ" << res << endl;
}

void AlgorithmTest::subFloat()
{
	float a = 1.1;
	float b = 1.2;
	float res = algorithmPtr->sub(a, b);
	cout << " �㷨���ԣ�  sub(float)ִ�����: " << " ���aΪ" << a << "; ���bΪ" << b << "; ���Ϊ" << res << endl;
}



