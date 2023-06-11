#ifndef __REALTIME_H__
#define __REALTIME_H__

#include <iostream>
#include <string>

#include  "common.h"
#include "i_realtime.h"

using namespace std;

BEGINE_NAMESPACE(ns_realtimedb)

class  RealtimeDB : public IRealtimeDB
{
public:
	RealtimeDB() {};
	~RealtimeDB() {};

public:
	int add(int a, int b);

public:
	virtual int initialize() override;
	virtual int start() override;
	virtual int stop() override;
	virtual int clear() override;

	static const int& getComponentGuid()
	{
		return COM_ID_REALTIMEDB;
	}

};

END_NAMESPACE
#endif