#include "circle.h"

using namespace ns_lib_simple_demo;
using namespace ns_lib_bridging_model;

void SimpleDemoCircle::update()
{
	cout << "  simple demo -- �Ž�ģʽ  this is circle update " << endl;
	simpleDemoIDrawPtr->draw();
}
