#include "print.h"

BEGINENAMESPACE(ns_common)

void commonFuncPrint(string str)
{
	cout << " common²âÊÔ£ºthis is print by common module func; content is :"<< str << endl ;
}

void commonFuncPrintC(string str)
{
	cout << " common²âÊÔ£ºthis is print by common module func , call style is C; content is :" << str << endl;
}

ENDNAMESPACE