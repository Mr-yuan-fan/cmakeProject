#include "nodeTest.h"

#include <windows.h>

using namespace ns_node_test;



void NodeTest::executeNode()
{

	//������ʽ1
	//TCHAR commandLine[] = TEXT("node E:\\c++\\c++StudySln\\cmakeDemo\\bin\\win64\\debug\\nodejs\\index.js param1  param2");
	//system(commandLine);

	//char cmdLine[] = "node E:\\c++\\c++StudySln\\cmakeDemo\\bin\\win64\\debug\\nodejs\\index.js param1  param2";
	//system(cmdLine);

	//������ʽ2
	//WinExec("E:\\c++\\c++StudySln\\cmakeDemo\\bin\\win64\\debug\\nodejs\\start.bat param1 param2", SW_MAX);

	//������ʽ3
	char buf[1000];
	GetModuleFileName(nullptr, buf, 1000);

	string temp = buf;
	int index = temp.find_last_of("\\");
	auto newStr = temp.substr(0, index);

	string exePath = newStr + "\\nodejs\\node.exe";
	string jsPath = " "+ newStr + "\\nodejs\\index.js" + " " + "param1" + " " + "param2";


	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(
		LPCSTR(exePath.c_str()),
		LPSTR(jsPath.c_str()),
		NULL,
		NULL,
		false,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi))
	{
		return;
	}
	else
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}


void NodeTest::testExecute()
{
	cout << "-----------------------------------------\t node ���Կ�ʼ \t\t---------------------------------" << endl;

	executeNode();

	cout << "-----------------------------------------\t node ���Խ��� \t\t---------------------------------" << endl;
	cout << endl;
}