#ifndef __COMPONENT_TEST_H_
#define __COMPONENT_TEST_H_

#include "common.h"
#include <iostream>

BEGINE_NAMESPACE(ns_component_test)

class ComponentTest
{
public:

	ComponentTest() = default;
	~ComponentTest() = default;

public:

	void testExecute();

private:
	void realtimedbComTest();
};

typedef std::shared_ptr<ComponentTest>  ComponentTestPtr;

END_NAMESPACE
#endif