#include "print.h"

BEGINE_NAMESPACE(ns_common)

void commonFuncPrint(string str)
{
	cout << " common���ԣ�this is print by common module func; content is :"<< str << endl ;
}

void commonFuncPrintC(string str)
{
	cout << " common���ԣ�this is print by common module func , call style is C; content is :" << str << endl;
}

END_NAMESPACE
