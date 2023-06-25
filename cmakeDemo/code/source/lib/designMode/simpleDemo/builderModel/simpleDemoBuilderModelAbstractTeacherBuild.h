#ifndef __SIMPLE_DEMO_BUILDER_MODEL_ABSTRACTOR_TEACHER_BUILD_H__
#define __SIMPLE_DEMO_BUILDER_MODEL_ABSTRACTOR_TEACHER_BUILD_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoBuilderModelTeacher.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_builder_model)


class SimpleDemoBuilderModelAbstractorTeacherBuild
{
public:
	SimpleDemoBuilderModelAbstractorTeacherBuild() {}

	virtual ~SimpleDemoBuilderModelAbstractorTeacherBuild() {}


public:

	virtual void buildFirstSkill() = 0;

	virtual void buildSecondSkill() = 0;

	virtual SimpleDemoBuilderModelTeacher*  getTeacher() = 0;

};


END_NAMESPACE
END_NAMESPACE

#endif