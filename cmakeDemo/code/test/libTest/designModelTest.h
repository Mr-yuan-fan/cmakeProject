#ifndef __DESIGNMODEL_TEST_H_
#define __DESIGNMODEL_TEST_H_


#include "lib/designMode/simpleFactory.h"

using namespace ns_lib_simple_factory;

BEGINENAMESPACE(ns_designmodel_simplefatory_test)

class SimpleFatoryTest
{
public:

	SimpleFatoryTest()
	{
		init();
	};
	~SimpleFatoryTest() {};

public:

	void testExecute();

private:

	void simpleFactoryDemo();

private:

	void init();

private:

	shared_ptr<SimpleFactory> simpleFactoryPtr;

};


ENDNAMESPACE
#endif
