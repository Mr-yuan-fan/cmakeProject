#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include <string>
#include "i_algorithm.h"
#include "dll//common/common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_algorithm)
class ALGORITHM_API Algorithm
{
public:
	Algorithm();
	~Algorithm();

public:
	int add(int a, int b);
	float add(float a, float b);
	int sub(int a, int b);
	float sub(float a, float b);

private:

};


ENDNAMESPACE
#endif