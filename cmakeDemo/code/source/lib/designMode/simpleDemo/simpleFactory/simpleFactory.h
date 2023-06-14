#ifndef __LIB_SIMPLE_FACTORY_H__
#define __LIB_SIMPLE_FACTORY_H__

#include <iostream>
#include <string>
#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_simple_factory)


class SimpleDemoSimpleFactory
{
public:
	SimpleDemoSimpleFactory() {};
	~SimpleDemoSimpleFactory() {};

public:

	void demo();

private:

};

typedef shared_ptr<SimpleDemoSimpleFactory>  SimpleDemoSimpleFactorySimpleFactoryPtr;


END_NAMESPACE
END_NAMESPACE

#endif