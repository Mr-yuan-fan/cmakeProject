#ifndef __I_DRAW_H
#define __I_DRAW_H

#include "common.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_bridging_model)

class SimpleDemoIDraw
{
public:

	SimpleDemoIDraw() {};
	virtual ~SimpleDemoIDraw() {};

public:

	virtual void draw() = 0 ;

};


END_NAMESPACE
END_NAMESPACE

#endif