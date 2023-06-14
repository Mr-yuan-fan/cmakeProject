#ifndef __SIMPLE_DEMO_OBSERVER_BASE_H__
#define __SIMPLE_DEMO_OBSERVER_BASE_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_observer_method)


class SimpleDemoObserverBase
{
public:

	SimpleDemoObserverBase() {};
	virtual ~SimpleDemoObserverBase() {};

public:

	virtual void update();

};


END_NAMESPACE
END_NAMESPACE

#endif