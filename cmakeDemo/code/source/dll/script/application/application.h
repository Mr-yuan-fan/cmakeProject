#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include <string>
#include "i_algorithm.h"
#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_algorithm)
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

typedef shared_ptr<Algorithm>  AlgorithmPtr;

END_NAMESPACE
#endif