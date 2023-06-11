
#include "framework_common_utitly.h"

#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;

BEGINE_NAMESPACE(framework_common)

 bool loadLibrary(vector<string> dllPath)
{

	if (dllPath.empty())
	{
		cout << "invalid dll path" << endl;
	}

	for (auto iter = dllPath.begin(); iter!= dllPath.end(); ++iter)
	{
		HMODULE handle = LoadLibrary((*iter).c_str());
	}
	return true;
}


END_NAMESPACE
