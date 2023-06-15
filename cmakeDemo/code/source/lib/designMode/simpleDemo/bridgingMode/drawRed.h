#ifndef __I_SIMPLE_DEMO_DRAW_RED_H
#define __I_SIMPLE_DEMO_DRAW_RED_H

#include "common.h"
#include "i_draw.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_bridging_model)

class SimpleDemoDrawRed : public SimpleDemoIDraw
{
public:

	SimpleDemoDrawRed() {};
	virtual ~SimpleDemoDrawRed() {};

public:

	virtual void draw() override ;
};


END_NAMESPACE
END_NAMESPACE

#endif