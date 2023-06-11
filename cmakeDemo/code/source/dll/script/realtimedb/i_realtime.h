#ifndef __I_REALTIME_H__
#define __I_REALTIME_H__

#include <iostream>
#include <string>

#include  "common.h"
#include "i_component_manager.h"
#include "component_register.h"

using namespace std;

static const int COM_ID_REALTIMEDB = 10002;

BEGINE_NAMESPACE(ns_realtimedb)

class  IRealtimeDB : public IComponent
{
public:
	IRealtimeDB() {};
	~IRealtimeDB() {};

public:
	virtual int add(int a, int b) = 0;

public:
	virtual int initialize() = 0;
	virtual int start() = 0;
	virtual int stop() = 0;
	virtual int clear() = 0;

	static const int& getComponentGuid()
	{
		return COM_ID_REALTIMEDB;
	}

};

END_NAMESPACE
#endif