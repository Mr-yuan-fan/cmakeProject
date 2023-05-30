#ifndef __COMMON_UTITLY_H__
#define __COMMON_UTITLY_H__

#ifndef COMMON_API
#ifdef COMMON_API_FLAG
#define COMMON_API __declspec(dllexport)
#else
#define COMMON_API __declspec(dllimport)
#endif 
#endif // !COMMON_API

#include <iostream>
#include <string>
using namespace std;

#define COMMON_PRINT(str) cout<<"this is print by common module define; content is : "<< str << endl;

#define int32_t int

#define BEGINENAMESPACE( name ) namespace name{

#define ENDNAMESPACE }

#endif