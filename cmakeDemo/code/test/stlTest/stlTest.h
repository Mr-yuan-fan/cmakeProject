#ifndef __STL_TEST_H_
#define __STL_TEST_H_

#include  "common.h"
#include  <iostream>
using namespace std;

BEGINE_NAMESPACE(ns_stl_test)

class StlTest
{
public:

	StlTest() {};
	~StlTest() {};

public:

	void testExecute();

private:

	void stlArrayTest();
	void stlVectorTest();
	void stlDequeTest();
	void stlForwardList();
	void stlList();
	void stlStack();
	void stlQueue();
	void stlPriorityQueue();
	void stlSet();
};

typedef shared_ptr<StlTest>  StlTestPtr;

END_NAMESPACE
#endif