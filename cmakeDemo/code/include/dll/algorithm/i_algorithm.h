#ifndef __I_ALGORITHM_H__
#define __I_ALGORITHM_H__

#include <iostream>
#include <string>
using namespace std;

#ifndef ALGORITHM_API
#ifdef ALGORITHM_API_FLAG
#define ALGORITHM_API __declspec(dllexport)
#else
#define ALGORITHM_API __declspec(dllimport)
#endif // !ALGORITHM_API_FLAG
#endif // !ALGORITHM_API

#endif