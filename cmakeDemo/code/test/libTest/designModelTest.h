#ifndef __DESIGNMODEL_TEST_H_
#define __DESIGNMODEL_TEST_H_


#include "lib/designMode/simpleFactory.h"

using namespace ns_lib_simple_factory;

BEGINENAMESPACE(ns_designmodel_simplefatory_test)

class SimpleFactoryTest
{
public:

	SimpleFactoryTest()
	{
		simpleFactoryPtr = SimpleFactoryPtr(new SimpleFactory);
	};
	~SimpleFactoryTest() {};

public:

	void testExecute();

private:

	void simpleFactoryDemo();

private:

	SimpleFactoryPtr simpleFactoryPtr;

};

typedef shared_ptr<SimpleFactoryTest>  SimpleFactoryTestPtr;


ENDNAMESPACE
#endif
