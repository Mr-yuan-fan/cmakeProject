#ifndef __SIMPLE_DEMO_CIRCLE_H
#define __SIMPLE_DEMO_CIRCLE_H

#include "common.h"
#include "i_shape.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_bridging_model)

class SimpleDemoCircle : public SimpleDemoIShape
{
public:

	SimpleDemoCircle(SimpleDemoIDraw* ptr) :SimpleDemoIShape(ptr) {};
	virtual ~SimpleDemoCircle() {};

public:

	virtual void update() override;
};


END_NAMESPACE
END_NAMESPACE

#endif