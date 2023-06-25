#include "simpleDemoDesignModelTest.h"

using namespace ns_designmodel_simple_demo_test;

void SimpleDemoDesignModelTest::builderModel()
{
	cout << "this is 建造者模式 : " << endl;

	SimpleDemoBuilderModelAbstractorTeacherBuild* simpleDemoBuilderModelAbstractorTeacherBuildPtr1 = new SimpleDemoBuilderModelChineseTeacherBuild();
	SimpleDemoBuilderModelDirector* simpleDemoBuilderModelDirectorPtr1 = new SimpleDemoBuilderModelDirector(simpleDemoBuilderModelAbstractorTeacherBuildPtr1);

	delete simpleDemoBuilderModelAbstractorTeacherBuildPtr1;
	delete simpleDemoBuilderModelDirectorPtr1;

	SimpleDemoBuilderModelAbstractorTeacherBuild* simpleDemoBuilderModelAbstractorTeacherBuildPtr2 = new SimpleDemoBuilderModelMathTeacherBuild();
	SimpleDemoBuilderModelDirector* simpleDemoBuilderModelDirectorPtr2 = new SimpleDemoBuilderModelDirector(simpleDemoBuilderModelAbstractorTeacherBuildPtr2);

	delete simpleDemoBuilderModelAbstractorTeacherBuildPtr2;
	delete simpleDemoBuilderModelDirectorPtr2;

	cout << endl;
}

void SimpleDemoDesignModelTest::prototypeModel()
{
	cout << "this is 原型模式 : " << endl;

	SimpleDemoPrototypeBase* SimpleDemoPrototypeBase1 = new SimpleDemoPrototypeChild();
	SimpleDemoPrototypeBase1->play();

	SimpleDemoPrototypeBase* SimpleDemoPrototypeBase2 = SimpleDemoPrototypeBase1->clone();
	SimpleDemoPrototypeBase2->play();

	delete SimpleDemoPrototypeBase1;
	delete SimpleDemoPrototypeBase2;

	cout << endl;
}

void SimpleDemoDesignModelTest::simpleFactory()
{
	cout << "this is 简单工厂模式 : " << endl;

	SimpleDemoFactory* simpleDemoFactoryPtr = new SimpleDemoFootballFactory();
	SimpleDemoProduct* simpleDemoProductPtr = simpleDemoFactoryPtr->createProduct();
	simpleDemoProductPtr->show();

	delete simpleDemoFactoryPtr;
	delete simpleDemoProductPtr;

	simpleDemoFactoryPtr = new SimpleDemoLolFactory();
	simpleDemoProductPtr = simpleDemoFactoryPtr->createProduct();
	simpleDemoProductPtr->show();

	delete simpleDemoFactoryPtr;
	delete simpleDemoProductPtr;

	simpleDemoFactoryPtr = nullptr ;
	simpleDemoProductPtr = nullptr;

	cout << endl;
}

void SimpleDemoDesignModelTest::bridgingModelTest()
{
	cout << "this is 桥接模式 : " << endl;

	SimpleDemoIDraw* simpleDemoDrawRedPtr = new SimpleDemoDrawRed();
	SimpleDemoIDraw* simpleDemoDrawBlackPtr = new SimpleDemoDrawBlack();

	SimpleDemoIShape* simpleDemoCirclePtr = new SimpleDemoCircle(simpleDemoDrawRedPtr);
	simpleDemoCirclePtr->update();

	SimpleDemoIShape* simpleDemoRectanglePtr = new SimpleDemoRectangle(simpleDemoDrawBlackPtr);
	simpleDemoRectanglePtr->update();

	delete simpleDemoDrawRedPtr;
	delete simpleDemoDrawBlackPtr;
	delete simpleDemoCirclePtr;
	delete simpleDemoRectanglePtr;

	cout << endl;
}

void SimpleDemoDesignModelTest::decoratorModelTest()
{
	cout << "this is 装饰器模式 : " << endl;

	ISimpleDemoDecorator* iSimpleDemoDecoratorCarPtr = new SimpleDemoDecoratorCarGame();
	ISimpleDemoDecorator* iSimpleDemoDecoratorLolPtr = new SimpleDemoDecoratorLolGame();

	iSimpleDemoDecoratorCarPtr->skill(); //只会汽车游戏
	iSimpleDemoDecoratorLolPtr->skill();//只会LOL游戏

	ISimpleDemoDecorator* iSimpleDemoDecoratorBasketballWithCarGamePtr = new SimpleDemoDecoratorBasketballGame(iSimpleDemoDecoratorCarPtr);
	iSimpleDemoDecoratorBasketballWithCarGamePtr->skill(); //既会篮球，又会汽车

	ISimpleDemoDecorator* iSimpleDemoDecoratorBasketballWithLolGamePtr = new SimpleDemoDecoratorBasketballGame(iSimpleDemoDecoratorLolPtr);
	iSimpleDemoDecoratorBasketballWithLolGamePtr->skill(); //既会篮球，又会LOL

	ISimpleDemoDecorator* iSimpleDemoDecoratorFootballGamePtr = new SimpleDemoDecoratorFootballGame(iSimpleDemoDecoratorBasketballWithCarGamePtr);
	iSimpleDemoDecoratorFootballGamePtr->skill(); //既会足球，篮球，又会汽车,

	delete iSimpleDemoDecoratorCarPtr;
	delete iSimpleDemoDecoratorLolPtr;
	delete iSimpleDemoDecoratorBasketballWithCarGamePtr;
	delete iSimpleDemoDecoratorBasketballWithLolGamePtr;
	delete iSimpleDemoDecoratorFootballGamePtr;

	iSimpleDemoDecoratorCarPtr = nullptr;
	iSimpleDemoDecoratorLolPtr = nullptr;
	iSimpleDemoDecoratorBasketballWithCarGamePtr = nullptr;
	iSimpleDemoDecoratorBasketballWithLolGamePtr = nullptr;
	iSimpleDemoDecoratorFootballGamePtr = nullptr;

	cout << endl;
}

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

	templateMethodTest();//模板方法

	strategyPatternTest();//策略模式

	observevModelTest();//观察者模式

	decoratorModelTest();//装饰器模式
	
	bridgingModelTest();//桥接模式

	simpleFactory();//简单工厂模式

	prototypeModel();//原型模式	`

	builderModel();//建造者模式
	cout << "-----------------------------------------\t simpleDemo 设计模式 测试结束 \t---------------------------------" << endl;
	cout << endl;
}


