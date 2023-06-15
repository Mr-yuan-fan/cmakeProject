#ifndef __I_SIMPLE_DEMO_LOL_FACTORY_H
#define __I_SIMPLE_DEMO_LOL_FACTORY_H

#include "common.h"
#include "factory.h"
#include "lolProduct.h"


#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simplefactory_model)

class SimpleDemoLolFactory : public SimpleDemoFactory
{
public:

	SimpleDemoLolFactory() {};
	virtual ~SimpleDemoLolFactory() {};

public:

	virtual SimpleDemoProduct* createProduct() override;
};


END_NAMESPACE
END_NAMESPACE

#endif