#ifndef __ALGORITHM_TEST_H_
#define __ALGORITHM_TEST_H_


#include "dll/algorithm/algorithm.h"

using namespace ns_algorithm;

BEGINENAMESPACE(ns_algorithm_test)


class AlgorithmTest
{
public:

	AlgorithmTest()
	{
		algorithmPtr = AlgorithmPtr(new Algorithm);
	};

	~AlgorithmTest() {};

public:

	void testExecute();

private:

	void addInt();

	void addFloat();

	void subInt();

	void subFloat();

private:

	AlgorithmPtr algorithmPtr;
};

typedef shared_ptr<AlgorithmTest>  AlgorithmTestPtr;

ENDNAMESPACE
#endif