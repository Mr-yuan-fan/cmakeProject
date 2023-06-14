#ifndef __SIMPLE_DEMO_BASKETBALL_GAME_H__
#define __SIMPLE_DEMO_BASKETBALL_GAME_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoGame.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_template_method)


class SimpleDemoBasketballGame : public SimpleDemoGame
{
public:

	SimpleDemoBasketballGame() {};
	~SimpleDemoBasketballGame() {};

public:

	virtual void startGame() override;

};


END_NAMESPACE
END_NAMESPACE

#endif