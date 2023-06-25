#ifndef __SIMPLE_DEMO_BUILDER_MODEL_MATH_TEACHER_BUILD_H__
#define __SIMPLE_DEMO_BUILDER_MODEL_MATH_TEACHER_BUILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoBuilderModelAbstractTeacherBuild.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_builder_model)


class SimpleDemoBuilderModelMathTeacherBuild : public SimpleDemoBuilderModelAbstractorTeacherBuild
{

public:

	SimpleDemoBuilderModelMathTeacherBuild()
	{
		teacherPtr = new SimpleDemoBuilderModelTeacher() ;
	}

	~SimpleDemoBuilderModelMathTeacherBuild()
	{
		delete teacherPtr ;
	}

public:

	void buildFirstSkill () override
	{
		teacherPtr->setFirstSkill("math");
	};

	void buildSecondSkill() override
	{
		teacherPtr->setSecondSkill("chinese");
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