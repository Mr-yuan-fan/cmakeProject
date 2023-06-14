#ifndef __SIMPLE_DEMO_OBSERVER_NOTIFY_MANAGER_H__
#define __SIMPLE_DEMO_OBSERVER_NOTIFY_MANAGER_H__

#include <iostream>
#include <string>
#include <list>

#include  "common.h"
#include "simpleDemoObserverBase.h"
#include "simpleDemoObserverFirstChild.h"
#include "simpleDemoObserverSecondChild.h"

using namespace std;

BEGINE_NAMESPACE(ns_lib_simple_demo)
BEGINE_NAMESPACE(ns_lib_observer_method)


class SimpleDemoObserverNotifyManager
{
public:

	SimpleDemoObserverNotifyManager() {};
	virtual ~SimpleDemoObserverNotifyManager() {};

public:

	void add(SimpleDemoObserverBase * simpleDemoObserverBasePtr);

	void remove(SimpleDemoObserverBase * simpleDemoObserverBasePtr);

	void notify();

private:

	list<SimpleDemoObserverBase*> m_observer_list;
};


END_NAMESPACE
END_NAMESPACE

#endif