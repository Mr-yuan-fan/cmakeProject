#ifndef __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_
#define __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_

//simple demo 模板方法
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoBasketballGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoFootballGame.h"

//simple demo 策略模式
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoCalculation.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoAdd.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoSub.h"

//simple demo 观察者模式
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverBase.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverNotifyManager.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverFirstChild.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverSecondChild.h"


using namespace ns_lib_simple_demo;
using namespace ns_lib_template_method;
using namespace ns_lib_stategy_pattern;
using namespace ns_lib_observer_method;

BEGINE_NAMESPACE(ns_designmodel_simple_demo_template_method_test)

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

private:

};

typedef shared_ptr<SimpleDemoDesignModelTest> SimpleDemoDesignModelTestPtr;


END_NAMESPACE
#endif
