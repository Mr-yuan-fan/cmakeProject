#include "designModelTest.h"


using namespace ns_lib_simple_factory;
using namespace ns_designmodel_simplefatory_test;


void SimpleFactoryTest::simpleFactoryDemo()
{
	simpleFactoryPtr->demo();
}


void SimpleFactoryTest::testExecute()
{
	cout << "-----------------------------------------\t simpleFactory ���Կ�ʼ \t---------------------------------" << endl;

	//demo����
	simpleFactoryDemo();

	cout << "-----------------------------------------\t simpleFactory ���Խ��� \t---------------------------------" << endl;
	cout << endl;
}


