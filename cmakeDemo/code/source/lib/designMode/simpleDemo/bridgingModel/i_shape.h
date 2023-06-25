#ifndef __I_SIMPLE_DEMO_SHAPE_H
#define __I_SIMPLE_DEMO_SHAPE_H

#include "common.h"
#include "i_draw.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_bridging_model)

class SimpleDemoIShape
{
public:

	SimpleDemoIShape(SimpleDemoIDraw* ptr) { simpleDemoIDrawPtr = ptr; };
	virtual ~SimpleDemoIShape() {};

public:

	virtual void update() = 0;

protected:

	SimpleDemoIDraw* simpleDemoIDrawPtr;
};


END_NAMESPACE
END_NAMESPACE

#endif