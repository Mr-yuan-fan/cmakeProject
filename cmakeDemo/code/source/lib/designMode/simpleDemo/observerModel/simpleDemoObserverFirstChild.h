#ifndef __SIMPLE_DEMO_OBSERVER_FIRST_CHILD_H__
#define __SIMPLE_DEMO_OBSERVER_FIRST_CHILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoObserverBase.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_observer_method)


class SimpleDemoObserverFirstChild : public SimpleDemoObserverBase
{
public:

	SimpleDemoObserverFirstChild() {};
	~SimpleDemoObserverFirstChild() {};

public:

	virtual void update() override;

};


END_NAMESPACE
END_NAMESPACE

#endif