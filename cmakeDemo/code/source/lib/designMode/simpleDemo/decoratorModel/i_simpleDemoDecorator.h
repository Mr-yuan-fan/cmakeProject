#ifndef __I_SIMPLE_DEMO_DECORATOR_H__
#define __I_SIMPLE_DEMO_DECORATOR_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_decorator_model)


class ISimpleDemoDecorator
{
public:

	ISimpleDemoDecorator() {};
	virtual ~ISimpleDemoDecorator() {};

public:

	virtual void skill();

};


END_NAMESPACE
END_NAMESPACE

#endif