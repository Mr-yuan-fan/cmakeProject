#include "algorithm.h"

BEGINE_NAMESPACE(ns_algorithm)

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

int Algorithm::add(int a, int b)
{
	return a + b;
}

float Algorithm::add(float a, float b)
{
	return a + b;
}

int Algorithm::sub(int a, int b)
{
	return a - b;
}

float Algorithm::sub(float a, float b)
{
	return a - b;
}

END_NAMESPACE
