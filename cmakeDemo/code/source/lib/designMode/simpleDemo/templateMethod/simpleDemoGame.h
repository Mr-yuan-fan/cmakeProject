#ifndef __SIMPLE_DEMO_GAME_H__
#define __SIMPLE_DEMO_GAME_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_template_method)


class SimpleDemoGame
{
public:

	SimpleDemoGame() {};
	virtual ~SimpleDemoGame() {};

public:

	void run();

protected:

	virtual void startGame();

private:

	void initGame();
	void stopGame();

};


END_NAMESPACE
END_NAMESPACE

#endif