#ifndef __SIMPLE_DEMO_DECORATOR_BASKETBALL_GAME_H__
#define __SIMPLE_DEMO_DECORATOR_BASKETBALL_GAME_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoDecorator.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_decorator_model)


class SimpleDemoDecoratorBasketballGame : public SimpleDemoDecorator
{
public:

	SimpleDemoDecoratorBasketballGame(ISimpleDemoDecorator * ptr):SimpleDemoDecorator(ptr){ };
	~SimpleDemoDecoratorBasketballGame() {};

public:

	virtual void skill() override;

};


END_NAMESPACE
END_NAMESPACE

#endif