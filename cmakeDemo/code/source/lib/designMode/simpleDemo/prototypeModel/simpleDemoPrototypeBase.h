#ifndef __SIMPLE_DEMO_PROTOTYPE_BASE_H__
#define __SIMPLE_DEMO_PROTOTYPE_BASE_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_prototype_model)


class SimpleDemoPrototypeBase
{
public:

	virtual SimpleDemoPrototypeBase* clone() = 0;

	virtual void play() = 0;

};


END_NAMESPACE
END_NAMESPACE

#endif