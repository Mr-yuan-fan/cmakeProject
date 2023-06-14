#ifndef __SIMPLE_DEMO_CALCULATION_H__
#define __SIMPLE_DEMO_CALCULATION_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_stategy_pattern)


class SimpleDemoCalculation
{
public:

	SimpleDemoCalculation() {};
	virtual ~SimpleDemoCalculation() {};

public:

	virtual void operation();

};


END_NAMESPACE
END_NAMESPACE

#endif