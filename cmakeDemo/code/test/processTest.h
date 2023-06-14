#ifndef __PROCESS_TEST_H_
#define __PROCESS_TEST_H_

#include "algorithmTest.h"
#include "commonTest.h"
#include "designModel/simpleDemoDesignModelTest.h"
#include "nodeTest.h"
#include "threadTest.h"
#include "componentTest.h"
#include "stlTest.h"

#include <windows.h>

using namespace ns_algorithm_test;
using namespace ns_common_test;
using namespace ns_node_test;
using namespace ns_designmodel_simple_demo_template_method_test;
using namespace ns_thread_test;
using namespace ns_component_test;
using namespace ns_stl_test;


BEGINE_NAMESPACE(ns_process_test)

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
	void init();

private:

	AlgorithmTestPtr       algorithmTestPtr;
	CommonTestPtr          commonTestPtr;
	SimpleDemoDesignModelTestPtr   simpleDemoDesignModelTestPtr;
	NodeTestPtr            nodeTestPtr;
	ThreadTestPtr          threadTestPtr;
	ComponentTestPtr       componentTestPtr;
	StlTestPtr             stlTestPtr;
};



END_NAMESPACE
#endif






