#include "simpleDemoGame.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_template_method;


void SimpleDemoGame::run()
{
	initGame();
	startGame();
	stopGame();
}

void SimpleDemoGame::startGame()
{
	cout << "  simple demo -- 模板方法  step2:开始游戏" << endl;
}

void SimpleDemoGame::initGame()
{
	cout << "  simple demo -- 模板方法  step1:初始化游戏" << endl;
}

void SimpleDemoGame::stopGame()
{
	cout << "  simple demo -- 模板方法  step3:停止游戏" << endl;
}
