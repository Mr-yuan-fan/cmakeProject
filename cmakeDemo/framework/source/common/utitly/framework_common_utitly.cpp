
#include "framework_common_utitly.h"

#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;

#define MAX_MODULE_PATH 1000
#define DOUBLE_QUOTATION_MARKS "\\"

BEGINE_NAMESPACE(framework_common)

string getModulePath(string dllName)
{
	char cModulePath[MAX_MODULE_PATH];
	GetModuleFileName(nullptr, cModulePath, MAX_MODULE_PATH);

	string modulePathStr = cModulePath;
	int32_t index = modulePathStr.find_last_of(DOUBLE_QUOTATION_MARKS);

	string basePath = modulePathStr.substr(0, index);
	string commonDllPath = basePath + "\\" + dllName;

	return commonDllPath;
}

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
