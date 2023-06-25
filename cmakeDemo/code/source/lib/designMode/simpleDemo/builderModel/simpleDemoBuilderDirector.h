#ifndef __SIMPLE_DEMO_BUILDER_MODEL_DIRECTOR_H__
#define __SIMPLE_DEMO_BUILDER_MODEL_DIRECTOR_H__

#include <iostream>
#include <string>

#include  "common.h"
#include  "simpleDemoBuilderModelAbstractTeacherBuild.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_builder_model)


class SimpleDemoBuilderModelDirector
{

public:

	SimpleDemoBuilderModelDirector(SimpleDemoBuilderModelAbstractorTeacherBuild * buildPtr) 
	{ 
		abstractorBuildPtr = buildPtr;
	};

	~SimpleDemoBuilderModelDirector() {};

public:

	void Create()
	{
		this->abstractorBuildPtr->buildFirstSkill();
		this->abstractorBuildPtr->buildSecondSkill();
	}

private:

	SimpleDemoBuilderModelAbstractorTeacherBuild* abstractorBuildPtr;
};


END_NAMESPACE
END_NAMESPACE

#endif