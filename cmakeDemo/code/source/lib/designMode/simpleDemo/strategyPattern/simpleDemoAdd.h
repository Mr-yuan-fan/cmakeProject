#ifndef __SIMPLE_DEMO_ADD_H__
#define __SIMPLE_DEMO_ADD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoCalculation.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_stategy_pattern)


class SimpleDemoAdd : public SimpleDemoCalculation
{
public:

	SimpleDemoAdd() {};
	~SimpleDemoAdd() {};

public:

	virtual void operation() override;

};


END_NAMESPACE
END_NAMESPACE

#endif