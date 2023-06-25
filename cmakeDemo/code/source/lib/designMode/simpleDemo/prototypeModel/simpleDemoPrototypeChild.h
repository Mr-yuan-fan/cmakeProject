#ifndef __SIMPLE_DEMO_PROTOTYPE_FIRST_CHILD_H__
#define __SIMPLE_DEMO_PROTOTYPE_FIRST_CHILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoPrototypeBase.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_prototype_model)


class SimpleDemoPrototypeChild : public SimpleDemoPrototypeBase
{

public:

	virtual SimpleDemoPrototypeBase* clone() override
	{
		return new SimpleDemoPrototypeChild();
	}

	virtual void play() override
	{
		cout << "  simple demo -- 原型模式  this is simpleDemoPrototypeFirstChild play " << endl;
	}

};


END_NAMESPACE
END_NAMESPACE

#endif