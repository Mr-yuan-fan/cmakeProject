#include "processTest.h"

using namespace ns_process_test;

void ProcessTest::init()
{
	algorithmTestPtr				=     AlgorithmTestPtr(new AlgorithmTest);
	commonTestPtr					=     CommonTestPtr(new CommonTest);
	nodeTestPtr						=     NodeTestPtr(new NodeTest);
	threadTestPtr					=     ThreadTestPtr(new ThreadTest);
	componentTestPtr				=     ComponentTestPtr(new ComponentTest);
	stlTestPtr                      =     StlTestPtr(new StlTest);
	simpleDemoDesignModelTestPtr    =     SimpleDemoDesignModelTestPtr(new SimpleDemoDesignModelTest);
}

void ProcessTest::allExecute()
{
	//algorithmTestPtr->testExecute();
	//commonTestPtr->testExecute();

	//nodeTestPtr->testExecute();
	//threadTestPtr->testExecute();
	//componentTestPtr->testExecute();
	//stlTestPtr->testExecute();

	simpleDemoDesignModelTestPtr->testExecute();


}

