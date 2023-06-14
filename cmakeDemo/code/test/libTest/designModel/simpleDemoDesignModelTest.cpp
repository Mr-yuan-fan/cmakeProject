#include "simpleDemoDesignModelTest.h"

using namespace ns_designmodel_simple_demo_template_method_test;

void SimpleDemoDesignModelTest::observevModelTest()
{
	cout << "this is 观察者模式 : " << endl;

	SimpleDemoObserverBase * simpleDemoObserverFirstChildPtr = new SimpleDemoObserverFirstChild();
	SimpleDemoObserverBase * simpleDemoObserverSecondChildPtr = new SimpleDemoObserverSecondChild();

	SimpleDemoObserverNotifyManager simpleDemoObserverNotifyManager;
	simpleDemoObserverNotifyManager.add(simpleDemoObserverFirstChildPtr);
	simpleDemoObserverNotifyManager.add(simpleDemoObserverSecondChildPtr);

	simpleDemoObserverNotifyManager.notify();
	simpleDemoObserverNotifyManager.remove(simpleDemoObserverFirstChildPtr);
	simpleDemoObserverNotifyManager.remove(simpleDemoObserverSecondChildPtr);

	delete simpleDemoObserverFirstChildPtr;
	delete simpleDemoObserverSecondChildPtr;

	simpleDemoObserverFirstChildPtr = nullptr;
	simpleDemoObserverSecondChildPtr = nullptr;

	cout << endl;
}

void SimpleDemoDesignModelTest::strategyPatternTest()
{
	cout << "this is 策略模式 : " << endl;
	SimpleDemoCalculation * simpleDemoAddPtr = new SimpleDemoAdd();
	simpleDemoAddPtr->operation();

	SimpleDemoCalculation * simpleDemoSubPtr = new SimpleDemoSub();
	simpleDemoSubPtr->operation();

	delete simpleDemoAddPtr;
	delete simpleDemoSubPtr;

	simpleDemoAddPtr = nullptr;
	simpleDemoSubPtr = nullptr;

	cout << endl;
}

void SimpleDemoDesignModelTest::templateMethodTest()
{
	cout << "this is 模板方法 : " << endl;

	SimpleDemoGame * basketballGamePtr = new SimpleDemoBasketballGame();
	basketballGamePtr->run();

	SimpleDemoGame * footballGamePtr = new SimpleDemoFootballGame();
	footballGamePtr->run();

	delete basketballGamePtr;
	delete footballGamePtr;

	basketballGamePtr = nullptr;
	footballGamePtr = nullptr;

	cout << endl;
}

void SimpleDemoDesignModelTest::testExecute()
{
	cout << "-----------------------------------------\t simpleDemo 设计模式 测试开始 \t---------------------------------" << endl;

	//模板方法
	templateMethodTest();

	//策略模式
	strategyPatternTest();

	//观察者模式
	observevModelTest();

	cout << "-----------------------------------------\t simpleDemo 设计模式 测试结束 \t---------------------------------" << endl;
	cout << endl;
}


