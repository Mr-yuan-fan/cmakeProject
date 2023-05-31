#include "processTest.h"

using namespace ns_process_test;

void ProcessTest::init()
{
	algorithmTestPtr = shared_ptr<AlgorithmTest> (new AlgorithmTest);
	commonTestPtr = shared_ptr<CommonTest>(new CommonTest);
	simpleFatoryTestPtr = shared_ptr<SimpleFatoryTest>(new SimpleFatoryTest);
	nodeTestPtr = shared_ptr<NodeTest>(new NodeTest);
	threadTestPtr = shared_ptr<ThreadTest>(new ThreadTest);

}

void ProcessTest::allExecute()
{
	//algorithmTestPtr->testExecute();
	//commonTestPtr->testExecute();
	//simpleFatoryTestPtr->testExecute();
	//nodeTestPtr->testExecute();
	threadTestPtr->testExecute();
}

