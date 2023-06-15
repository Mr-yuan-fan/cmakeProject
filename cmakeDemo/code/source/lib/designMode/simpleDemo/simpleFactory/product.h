#ifndef __I_SIMPLE_DEMO_PRODUCT_H
#define __I_SIMPLE_DEMO_PRODUCT_H

#include "common.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simplefactory_model)

class SimpleDemoProduct
{
public:

	SimpleDemoProduct() {};
	virtual ~SimpleDemoProduct() {};

public:

	virtual void show() = 0;

};


END_NAMESPACE
END_NAMESPACE

#endif