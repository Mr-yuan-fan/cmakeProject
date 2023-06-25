#ifndef __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_
#define __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_

//simple demo 模板方法
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoBasketballGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoFootballGame.h"

//simple demo 策略模式
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoAdd.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoSub.h"

//simple demo 观察者模式
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverNotifyManager.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverFirstChild.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverSecondChild.h"

//simple demo 装饰器模式
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecorator.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorBasketBallGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorCarGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorFootBallGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorLolGame.h"

//simple demo 桥接模式
#include "lib/designMode/simpleDemo/bridgingModel/circle.h"
#include "lib/designMode/simpleDemo/bridgingModel/rectangle.h"
#include "lib/designMode/simpleDemo/bridgingModel/drawBlack.h"
#include "lib/designMode/simpleDemo/bridgingModel/drawRed.h"

//简单工厂模式
#include "lib/designMode/simpleDemo/simpleFactory/footballFactory.h"
#include "lib/designMode/simpleDemo/simpleFactory/footballProduct.h"
#include "lib/designMode/simpleDemo/simpleFactory/lolFactory.h"
#include "lib/designMode/simpleDemo/simpleFactory/lolProduct.h"

//原型模式
#include "lib/designMode/simpleDemo/prototypeModel/simpleDemoPrototypeChild.h"

//建造者模式
#include "lib/designMode/simpleDemo/builderModel/simpleDemoBuilderModelMathTeacherBuild.h"
#include "lib/designMode/simpleDemo/builderModel/simpleDemoBuilderModelChineseTeacherBuild.h"
#include "lib/designMode/simpleDemo/builderModel/simpleDemoBuilderDirector.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_template_method;
using namespace ns_lib_stategy_pattern;
using namespace ns_lib_observer_method;
using namespace ns_lib_decorator_model;
using namespace ns_lib_bridging_model;
using namespace ns_lib_simplefactory_model;
using namespace ns_lib_prototype_model;
using namespace ns_lib_builder_model;

BEGINE_NAMESPACE(ns_designmodel_simple_demo_test)

class SimpleDemoDesignModelTest
{
public:

	SimpleDemoDesignModelTest() {};
	~SimpleDemoDesignModelTest() {};

public:

	void testExecute();

private:

	void templateMethodTest(); //模板方法

	void strategyPatternTest(); //策略模式

	void observevModelTest(); //观察者模式

	void decoratorModelTest(); //装饰器模式

	void bridgingModelTest(); //桥接模式

	void simpleFactory(); //简单工厂模式

	void prototypeModel(); //原型模式

	void builderModel(); //建造者模式

private:

};

typedef shared_ptr<SimpleDemoDesignModelTest> SimpleDemoDesignModelTestPtr;


END_NAMESPACE
#endif
