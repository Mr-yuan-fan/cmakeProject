#ifndef __LIB_SIMPLE_FACTORY_H__
#define __LIB_SIMPLE_FACTORY_H__

#include <iostream>
#include <string>
#include  "common.h"


using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_factory)

class SimpleFactory
{
public:
	SimpleFactory() {};
	~SimpleFactory() {};

public:

	void demo();

private:

};

typedef shared_ptr<SimpleFactory>  SimpleFactoryPtr;

END_NAMESPACE

#endif