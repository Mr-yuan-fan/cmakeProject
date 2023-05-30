#ifndef __PROCESS_TEST_H_
#define __PROCESS_TEST_H_

#include "algorithmTest.h"
#include "commonTest.h"
#include "designModelTest.h"
#include "nodeTest.h"

#include <windows.h>

using namespace ns_algorithm_test;
using namespace ns_common_test;
using namespace ns_node_test;
using namespace ns_designmodel_simplefatory_test;


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

	//Ö´ÐÐÈë¿Ú
	void allExecute();

private:

	shared_ptr<AlgorithmTest>      algorithmTestPtr;
	shared_ptr<CommonTest>         commonTestPtr;
	shared_ptr<SimpleFatoryTest>   simpleFatoryTestPtr;
	shared_ptr<NodeTest>           nodeTestPtr;

private:

	void init();
};


ENDNAMESPACE
#endif






