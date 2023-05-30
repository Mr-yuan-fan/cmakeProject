#ifndef __COMMON_TEST_H_
#define __COMMON_TEST_H_


#include "dll/common/print.h"

#include <windows.h>

using namespace ns_common;

BEGINENAMESPACE(ns_common_test)

class CommonTest
{
public:

	CommonTest() {};
	~CommonTest() {};

public:

	void testExecute();

private:

	void commonPrint();
	void commonPrintC();
};


ENDNAMESPACE
#endif