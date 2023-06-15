#ifndef SIMPLE_DEMO_DECORATOR_LOL_GAME
#define SIMPLE_DEMO_DECORATOR_LOL_GAME

#include <iostream>
#include <string>

#include  "common.h"
#include  "i_simpleDemoDecorator.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_decorator_model)


class SimpleDemoDecoratorLolGame : public ISimpleDemoDecorator
{
public:

	SimpleDemoDecoratorLolGame() {};
	~SimpleDemoDecoratorLolGame() {};

public:

	virtual void skill() override;

};


END_NAMESPACE
END_NAMESPACE

#endif