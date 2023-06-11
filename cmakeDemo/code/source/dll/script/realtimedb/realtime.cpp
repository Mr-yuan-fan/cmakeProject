#include "realtime.h"

BEGINE_NAMESPACE(ns_realtimedb)

COMPONENT_AUTO_REGISTER(RealtimeDB)

int RealtimeDB::initialize()
{
	return 0;
}

int RealtimeDB::start()
{
	return 0;
}

int RealtimeDB::stop()
{
	return 0;
}

int RealtimeDB::clear()
{
	return 0;
}

int RealtimeDB::add(int a, int b)
{
	return a + b;
}



END_NAMESPACE
