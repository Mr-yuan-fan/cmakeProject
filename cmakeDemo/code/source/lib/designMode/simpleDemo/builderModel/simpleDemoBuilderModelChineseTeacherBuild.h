#ifndef __SIMPLE_DEMO_BUILDER_MODEL_CHINESE_TEACHER_BUILD_H__
#define __SIMPLE_DEMO_BUILDER_MODEL_CHINESE_TEACHER_BUILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoBuilderModelAbstractTeacherBuild.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_builder_model)


class SimpleDemoBuilderModelChineseTeacherBuild : public SimpleDemoBuilderModelAbstractorTeacherBuild
{

public:

	SimpleDemoBuilderModelChineseTeacherBuild()
	{
		teacherPtr = new SimpleDemoBuilderModelTeacher() ;
	}

	~SimpleDemoBuilderModelChineseTeacherBuild()
	{
		delete teacherPtr ;
	}

public:

	void buildFirstSkill () override
	{
		teacherPtr->setFirstSkill("chinese");
	};

	void buildSecondSkill() override
	{
		teacherPtr->setSecondSkill("math");
	};

	virtual SimpleDemoBuilderModelTeacher*  getTeacher() override
	{
		return teacherPtr;
	}

private:

	SimpleDemoBuilderModelTeacher* teacherPtr;

};


END_NAMESPACE
END_NAMESPACE

#endif