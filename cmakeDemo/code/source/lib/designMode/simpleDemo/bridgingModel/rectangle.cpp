#include "rectangle.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_bridging_model;

void SimpleDemoRectangle::update()
{
	cout << "  simple demo -- �Ž�ģʽ  this is rectangle update " << endl;
	simpleDemoIDrawPtr->draw();
}
