#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>
#include <string>
#include "common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_common)

//����������ʽ�������÷�ʽһ��
void  COMMON_API commonFuncPrint(string str);
extern "C" void  COMMON_API commonFuncPrintC(string str);



ENDNAMESPACE

#endif