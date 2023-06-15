#ifndef __I_SIMPLE_DEMO_FOOTBALL_FACTORY_H
#define __I_SIMPLE_DEMO_FOOTBALL_FACTORY_H

#include "common.h"
#include "factory.h"
#include "footballProduct.h"


#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simplefactory_model)

class SimpleDemoFootballFactory : public SimpleDemoFactory
{
public:

	SimpleDemoFootballFactory() {};
	virtual ~SimpleDemoFootballFactory() {};

public:

	virtual SimpleDemoProduct* createProduct() override;
};


END_NAMESPACE
END_NAMESPACE

#endif