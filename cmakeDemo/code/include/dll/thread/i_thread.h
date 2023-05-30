#ifndef __I_THREAD_H__
#define __I_THREAD_H__


#include <iostream>
#include <string>
using namespace std;

#ifdef THREAD_API_FLAG
#ifndef THREAD_API
#define THREAD_API __declspec(dllexport)
#endif // !THREAD
#else
#define THREAD_API __declspec(dllimport)
#endif // !THREAD_API_FLAG


#endif