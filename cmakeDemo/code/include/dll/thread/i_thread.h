#ifndef __I_THREAD_H__
#define __I_THREAD_H__


#include <iostream>
#include <string>
using namespace std;

#ifndef THREAD_API
#ifdef THREAD_API_FLAG
#define THREAD_API __declspec(dllexport)
#else
#define THREAD_API __declspec(dllimport)
#endif // !THREAD_API_FLAG
#endif 

#endif