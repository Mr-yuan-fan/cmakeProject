#include "lolFactory.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_simplefactory_model;

SimpleDemoProduct* SimpleDemoLolFactory::createProduct()
{
	return new SimpleDemoLolProduct();
}
