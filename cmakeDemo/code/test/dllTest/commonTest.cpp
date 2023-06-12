#include "commonTest.h"
#include "framework_common_utitly.h"

using namespace ns_common_test;
using namespace ns_common;
using namespace framework_common;


#define COMMON_DLL_DEFINE "common.dll"

void CommonTest::commonPrint()
{
	commonFuncPrint("common str");
}

void CommonTest::commonPrintC()
{
	string commonDllPath = getModulePath(COMMON_DLL_DEFINE);

	HMODULE handle = LoadLibrary(commonDllPath.c_str());
	typedef void(*commonPrintC)(string str);

	commonPrintC commonPC = (commonPrintC)GetProcAddress(handle, "commonFuncPrintC");
	commonPC("print by load library");

	FreeLibrary(handle);
}


void CommonTest::testExecute()
{
	cout << "-----------------------------------------\t common 测试开始 \t\t---------------------------------" << endl;

	//常规函数
	commonPrint();

	//extern "C"函数
	commonPrintC();

	cout << "-----------------------------------------\t common 测试结束 \t\t---------------------------------" << endl;
	cout << endl;
}