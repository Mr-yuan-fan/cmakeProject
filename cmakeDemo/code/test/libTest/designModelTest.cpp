#include "designModelTest.h"


using namespace ns_lib_simple_factory;
using namespace ns_designmodel_simplefatory_test;


void SimpleFactoryTest::simpleFactoryDemo()
{
	simpleFactoryPtr->demo();
}


void SimpleFactoryTest::testExecute()
{
	cout << "-----------------------------------------\t simpleFactory 测试开始 \t---------------------------------" << endl;

	//demo函数
	simpleFactoryDemo();

	cout << "-----------------------------------------\t simpleFactory 测试结束 \t---------------------------------" << endl;
	cout << endl;
}


