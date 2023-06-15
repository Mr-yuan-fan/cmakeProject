#ifndef __I_SIMPLE_DEMO_LOL_PRODUCT_H
#define __I_SIMPLE_DEMO_LOL_PRODUCT_H

#include "common.h"
#include "product.h"

#include <iostream>
#include <string>

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simplefactory_model)

class SimpleDemoLolProduct : public SimpleDemoProduct
{
public:

	SimpleDemoLolProduct() {};
	virtual ~SimpleDemoLolProduct() {};

public:

	virtual void show() override;
};


END_NAMESPACE
END_NAMESPACE

#endif