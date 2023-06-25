#ifndef __SIMPLE_DEMO_BUILDER_MODEL_TEACHER_H__
#define __SIMPLE_DEMO_BUILDER_MODEL_TEACHER_H__

#include <iostream>
#include <string>

#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_builder_model)


class SimpleDemoBuilderModelTeacher
{
public:

	void setFirstSkill(const string& skill) 
	{
		this->firstSkill = skill;
	};

	void setSecondSkill(const string& skill)
	{
		this->secondSkill = skill;
	};

private:

	string firstSkill;
	string secondSkill;
};


END_NAMESPACE
END_NAMESPACE

#endif