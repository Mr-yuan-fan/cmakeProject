#ifndef __THREAD_H__
#define __THREAD_H__

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <stdexcept>
#include <queue>




#include "i_thread.h"
#include "dll//common/common_utitly.h"

using namespace std;

BEGINENAMESPACE(ns_thread)
class THREAD_API MThread
{
public:
	MThread() {};
	~MThread() {};

public:

	void demo();

private:

};

ENDNAMESPACE

#endif