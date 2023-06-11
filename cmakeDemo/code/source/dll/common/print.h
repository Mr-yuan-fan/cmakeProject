#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>
#include <string>
#include "common_utitly.h"
#include  "common.h"

using namespace std;

BEGINE_NAMESPACE(ns_common)

//两种声明方式，但调用方式一样
void  COMMON_API commonFuncPrint(string str);

extern "C" void  COMMON_API commonFuncPrintC(string str);



END_NAMESPACE

#endif