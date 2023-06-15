#ifndef __SIMPLE_DEMO_DECORATOR_H__
#define __SIMPLE_DEMO_DECORATOR_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "i_simpleDemoDecorator.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_decorator_model)


class SimpleDemoDecorator : public ISimpleDemoDecorator
{
public:

	SimpleDemoDecorator(ISimpleDemoDecorator * ptr) { iSimpleDemoDecoratorPtr = ptr; };
	~SimpleDemoDecorator() {};

public:

	virtual void skill() override;

private:
	ISimpleDemoDecorator* iSimpleDemoDecoratorPtr;
};


END_NAMESPACE
END_NAMESPACE

#endif