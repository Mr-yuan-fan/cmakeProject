#ifndef __I_DRAW_SIMPLE_DEMO_BLACK_H
#define __I_DRAW_SIMPLE_DEMO_BLACK_H

#include "common.h"
#include "i_draw.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_bridging_model)

class SimpleDemoDrawBlack : public SimpleDemoIDraw
{
public:

	SimpleDemoDrawBlack() {};
	virtual ~SimpleDemoDrawBlack() {};

public:

	virtual void draw() override;
};


END_NAMESPACE
END_NAMESPACE

#endif