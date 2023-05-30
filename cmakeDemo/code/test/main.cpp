#include <iostream>
#include <string>
#include <windows.h>

#include "processTest.h"

using namespace std;
using namespace ns_process_test;


int main()
{

	ProcessTest pt;
	pt.allExecute();

	system("pause");

	return 0;
}