#ifndef __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_
#define __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_

//simple demo ģ�巽��
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoBasketballGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoFootballGame.h"

//simple demo ����ģʽ
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoCalculation.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoAdd.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoSub.h"

//simple demo �۲���ģʽ
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

	void templateMethodTest(); //ģ�巽��

	void strategyPatternTest(); //����ģʽ

	void observevModelTest(); //�۲���ģʽ

private:

};

typedef shared_ptr<SimpleDemoDesignModelTest> SimpleDemoDesignModelTestPtr;


END_NAMESPACE
#endif
