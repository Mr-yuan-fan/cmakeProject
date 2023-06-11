#ifndef __NODE_TEST_H_
#define __NODE_TEST_H_


#include "lib/designMode/simpleFactory.h"


BEGINE_NAMESPACE(ns_node_test)

class NodeTest
{
public:

	NodeTest() {};
	~NodeTest() {};

public:

	void testExecute();

private:

	void executeNode();

};

typedef shared_ptr<NodeTest>  NodeTestPtr;

END_NAMESPACE
#endif