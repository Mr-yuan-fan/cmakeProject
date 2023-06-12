#ifndef __FRAMEWORK_COMMON_UTITLY_H__
#define __FRAMEWORK_COMMON_UTITLY_H__

#include "common.h"
#include "i_component_manager.h"

#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;

BEGINE_NAMESPACE(framework_common)

FRAMEWORK_COMMON_API string getModulePath(string dllPath);

FRAMEWORK_COMMON_API bool loadLibrary(vector<string> dllPath);

template<class T>
T* getService()
{
	IComponentManager* icomManager = getComponentManager();

	IComponent * iComPtr = nullptr;
	//icomManager->getComponent<T>();

	//T * myT = static_cast<T*>(iComPtr);
	//getComponent<T>();
	return getComponent<T>();;
}

END_NAMESPACE
#endif
