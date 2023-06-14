#include "simpleDemoDesignModelTest.h"

using namespace ns_designmodel_simple_demo_template_method_test;

void SimpleDemoDesignModelTest::observevModelTest()
{
	cout << "this is �۲���ģʽ : " << endl;

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
	cout << "this is ����ģʽ : " << endl;
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
	cout << "this is ģ�巽�� : " << endl;

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
	cout << "-----------------------------------------\t simpleDemo ���ģʽ ���Կ�ʼ \t---------------------------------" << endl;

	//ģ�巽��
	templateMethodTest();

	//����ģʽ
	strategyPatternTest();

	//�۲���ģʽ
	observevModelTest();

	cout << "-----------------------------------------\t simpleDemo ���ģʽ ���Խ��� \t---------------------------------" << endl;
	cout << endl;
}


