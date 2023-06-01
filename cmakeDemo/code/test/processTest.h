#ifndef __PROCESS_TEST_H_
#define __PROCESS_TEST_H_

#include "algorithmTest.h"
#include "commonTest.h"
#include "designModelTest.h"
#include "nodeTest.h"
#include "threadTest.h"


#include <windows.h>

using namespace ns_algorithm_test;
using namespace ns_common_test;
using namespace ns_node_test;
using namespace ns_designmodel_simplefatory_test;
using namespace ns_thread_test;


BEGINENAMESPACE(ns_process_test)

class ProcessTest
{
public:

	ProcessTest() 
	{
		init();
	};
	~ProcessTest() {};

public:

	//ִ�����
	void allExecute();

private:
	void init();

private:

	AlgorithmTestPtr algorithmTestPtr;
	CommonTestPtr commonTestPtr;
	SimpleFactoryTestPtr simpleFactoryTestPtr;
	NodeTestPtr nodeTestPtr;
	ThreadTestPtr threadTestPtr;
};

ENDNAMESPACE
#endif






