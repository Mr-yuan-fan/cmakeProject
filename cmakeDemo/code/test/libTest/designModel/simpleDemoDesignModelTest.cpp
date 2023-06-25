#include "simpleDemoDesignModelTest.h"

using namespace ns_designmodel_simple_demo_test;

void SimpleDemoDesignModelTest::builderModel()
{
	cout << "this is ������ģʽ : " << endl;

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
	cout << "this is ԭ��ģʽ : " << endl;

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
	cout << "this is �򵥹���ģʽ : " << endl;

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
	cout << "this is �Ž�ģʽ : " << endl;

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
	cout << "this is װ����ģʽ : " << endl;

	ISimpleDemoDecorator* iSimpleDemoDecoratorCarPtr = new SimpleDemoDecoratorCarGame();
	ISimpleDemoDecorator* iSimpleDemoDecoratorLolPtr = new SimpleDemoDecoratorLolGame();

	iSimpleDemoDecoratorCarPtr->skill(); //ֻ��������Ϸ
	iSimpleDemoDecoratorLolPtr->skill();//ֻ��LOL��Ϸ

	ISimpleDemoDecorator* iSimpleDemoDecoratorBasketballWithCarGamePtr = new SimpleDemoDecoratorBasketballGame(iSimpleDemoDecoratorCarPtr);
	iSimpleDemoDecoratorBasketballWithCarGamePtr->skill(); //�Ȼ������ֻ�����

	ISimpleDemoDecorator* iSimpleDemoDecoratorBasketballWithLolGamePtr = new SimpleDemoDecoratorBasketballGame(iSimpleDemoDecoratorLolPtr);
	iSimpleDemoDecoratorBasketballWithLolGamePtr->skill(); //�Ȼ������ֻ�LOL

	ISimpleDemoDecorator* iSimpleDemoDecoratorFootballGamePtr = new SimpleDemoDecoratorFootballGame(iSimpleDemoDecoratorBasketballWithCarGamePtr);
	iSimpleDemoDecoratorFootballGamePtr->skill(); //�Ȼ����������ֻ�����,

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

	templateMethodTest();//ģ�巽��

	strategyPatternTest();//����ģʽ

	observevModelTest();//�۲���ģʽ

	decoratorModelTest();//װ����ģʽ
	
	bridgingModelTest();//�Ž�ģʽ

	simpleFactory();//�򵥹���ģʽ

	prototypeModel();//ԭ��ģʽ	`

	builderModel();//������ģʽ
	cout << "-----------------------------------------\t simpleDemo ���ģʽ ���Խ��� \t---------------------------------" << endl;
	cout << endl;
}


