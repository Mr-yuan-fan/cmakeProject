#include "footballFactory.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_simplefactory_model;

SimpleDemoProduct* SimpleDemoFootballFactory::createProduct()
{
	return new SimpleDemoFootballProduct();
}
