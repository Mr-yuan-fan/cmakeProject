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
	cout << "  simple demo -- ģ�巽��  step2:��ʼ��Ϸ" << endl;
}

void SimpleDemoGame::initGame()
{
	cout << "  simple demo -- ģ�巽��  step1:��ʼ����Ϸ" << endl;
}

void SimpleDemoGame::stopGame()
{
	cout << "  simple demo -- ģ�巽��  step3:ֹͣ��Ϸ" << endl;
}
