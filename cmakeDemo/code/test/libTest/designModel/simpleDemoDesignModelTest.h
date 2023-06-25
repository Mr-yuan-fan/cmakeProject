#ifndef __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_
#define __DESIGN_MODEL_SIMPLE_DEMOL_TEST_H_

//simple demo ģ�巽��
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoBasketballGame.h"
#include "lib/designMode/simpleDemo/templateMethod/simpleDemoFootballGame.h"

//simple demo ����ģʽ
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoAdd.h"
#include "lib/designMode/simpleDemo/strategyPattern/simpleDemoSub.h"

//simple demo �۲���ģʽ
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverNotifyManager.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverFirstChild.h"
#include "lib/designMode/simpleDemo/observerModel/simpleDemoObserverSecondChild.h"

//simple demo װ����ģʽ
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecorator.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorBasketBallGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorCarGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorFootBallGame.h"
#include "lib/designMode/simpleDemo/decoratorModel/simpleDemoDecoratorLolGame.h"

//simple demo �Ž�ģʽ
#include "lib/designMode/simpleDemo/bridgingModel/circle.h"
#include "lib/designMode/simpleDemo/bridgingModel/rectangle.h"
#include "lib/designMode/simpleDemo/bridgingModel/drawBlack.h"
#include "lib/designMode/simpleDemo/bridgingModel/drawRed.h"

//�򵥹���ģʽ
#include "lib/designMode/simpleDemo/simpleFactory/footballFactory.h"
#include "lib/designMode/simpleDemo/simpleFactory/footballProduct.h"
#include "lib/designMode/simpleDemo/simpleFactory/lolFactory.h"
#include "lib/designMode/simpleDemo/simpleFactory/lolProduct.h"

//ԭ��ģʽ
#include "lib/designMode/simpleDemo/prototypeModel/simpleDemoPrototypeChild.h"

//������ģʽ
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

	void templateMethodTest(); //ģ�巽��

	void strategyPatternTest(); //����ģʽ

	void observevModelTest(); //�۲���ģʽ

	void decoratorModelTest(); //װ����ģʽ

	void bridgingModelTest(); //�Ž�ģʽ

	void simpleFactory(); //�򵥹���ģʽ

	void prototypeModel(); //ԭ��ģʽ

	void builderModel(); //������ģʽ

private:

};

typedef shared_ptr<SimpleDemoDesignModelTest> SimpleDemoDesignModelTestPtr;


END_NAMESPACE
#endif
