#ifndef __SIMPLE_DEMO_OBSERVER_SECOND_CHILD_H__
#define __SIMPLE_DEMO_OBSERVER_SECOND_CHILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoObserverBase.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_observer_method)


class SimpleDemoObserverSecondChild : public SimpleDemoObserverBase
{
public:

	SimpleDemoObserverSecondChild() {};
	~SimpleDemoObserverSecondChild() {};

public:

	virtual void update() override;

};


END_NAMESPACE
END_NAMESPACE

#endif