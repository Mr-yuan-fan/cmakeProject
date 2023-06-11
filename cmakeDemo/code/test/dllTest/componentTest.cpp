#include "componentTest.h"

//test
#include "framework_common_utitly.h"
#include <vector>
#include "component_manager.h"
#include "dll/script/realtimedb/i_realtime.h"

using namespace ns_realtimedb;
using namespace framework_common;
using namespace ns_component_test;
using namespace std;

#define REALTIME_DB_DLL_ABSOLUTE_PATH "E:\\programming\\c++\\mainStudySln\\cmakeDemo\\bin\\win64\\Debug\\realtimedb.dll"

void ComponentTest::realtimedbComTest()
{
	vector<string> dllPath;
	dllPath.push_back(REALTIME_DB_DLL_ABSOLUTE_PATH);

	//调用框架方法
	loadLibrary(dllPath);

	IRealtimeDB* realtimedbPtr = getService<IRealtimeDB>();
	if (nullptr == realtimedbPtr)
	{
		cout << "获取 IRealtimeDB 类指针失败！" << endl;
		return;
	}

	auto sum = realtimedbPtr->add(10, 10);
	cout << "调用realtimedb add 方法,返回值为: " << sum << endl;
}

void ComponentTest::testExecute()
{
	cout << "-----------------------------------------\t component 测试开始 \t\t---------------------------------" << endl;

	realtimedbComTest();

	cout << "-----------------------------------------\t component 测试结束 \t\t---------------------------------" << endl;
	cout << endl;
}