#ifndef __I_SIMPLE_DEMO_FACTORY_H
#define __I_SIMPLE_DEMO_FACTORY_H

#include "common.h"
#include "product.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simplefactory_model)

class SimpleDemoFactory
{
public:

	SimpleDemoFactory() {};
	virtual ~SimpleDemoFactory() {};

public:

	virtual SimpleDemoProduct* createProduct() = 0;

};


END_NAMESPACE
END_NAMESPACE

#endif