#ifndef __I_ALGORITHM_H__
#define __I_ALGORITHM_H__

#include <iostream>
#include <string>
using namespace std;

#ifdef ALGORITHM_API_FLAG
#ifndef ALGORITHM_API
#define ALGORITHM_API __declspec(dllexport)
#endif // !ALGORITHM_API
#else
#define ALGORITHM_API __declspec(dllimport)
#endif // !ALGORITHM_API_FLAG

#endif