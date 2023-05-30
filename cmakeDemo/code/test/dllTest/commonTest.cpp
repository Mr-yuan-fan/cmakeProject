#include "commonTest.h"

using namespace ns_common_test;
using namespace ns_common;


#define MAX_MODULE_PATH 1000
#define DOUBLE_QUOTATION_MARKS "\\"
#define COMMON_DLL_DEFINE "common.dll"

void CommonTest::commonPrint()
{
	commonFuncPrint("common str");
}

void CommonTest::commonPrintC()
{
	char cModulePath[MAX_MODULE_PATH];
	GetModuleFileName(nullptr, cModulePath, MAX_MODULE_PATH);

	string modulePathStr = cModulePath;
	int32_t index = modulePathStr.find_last_of(DOUBLE_QUOTATION_MARKS);

	string basePath = modulePathStr.substr(0, index);
	string commonDllPath = basePath + "\\" + COMMON_DLL_DEFINE;

	HMODULE handle = LoadLibrary(commonDllPath.c_str());
	typedef void(*commonPrintC)(string str);

	commonPrintC commonPC = (commonPrintC)GetProcAddress(handle, "commonFuncPrintC");
	commonPC("print by load library");

	FreeLibrary(handle);
}


void CommonTest::testExecute()
{
	cout << "-----------------------------------------\t common ���Կ�ʼ \t\t---------------------------------" << endl;

	//���溯��
	commonPrint();

	//extern "C"����
	commonPrintC();

	cout << "-----------------------------------------\t common ���Խ��� \t\t---------------------------------" << endl;
	cout << endl;
}