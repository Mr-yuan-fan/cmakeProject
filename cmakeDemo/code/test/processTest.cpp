#include "processTest.h"

using namespace ns_process_test;

void ProcessTest::init()
{
	//algorithmTestPtr = AlgorithmTestPtr(new AlgorithmTest);
	commonTestPtr = CommonTestPtr(new CommonTest);
	simpleFactoryTestPtr = SimpleFactoryTestPtr(new SimpleFactoryTest);
	nodeTestPtr = NodeTestPtr(new NodeTest);
	threadTestPtr = ThreadTestPtr(new ThreadTest);
	componentTestPtr = ComponentTestPtr(new ComponentTest);
}

void ProcessTest::allExecute()
{
	//algorithmTestPtr->testExecute();
	//commonTestPtr->testExecute();
	//simpleFactoryTestPtr->testExecute();
	//nodeTestPtr->testExecute();
	//threadTestPtr->testExecute();
	componentTestPtr->testExecute();


}

