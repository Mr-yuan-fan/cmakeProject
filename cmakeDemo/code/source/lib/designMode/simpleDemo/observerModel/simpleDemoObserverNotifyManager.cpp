#include "simpleDemoObserverNotifyManager.h"




using namespace ns_lib_simple_demo;
using namespace ns_lib_observer_method;


void SimpleDemoObserverNotifyManager::add(SimpleDemoObserverBase * simpleDemoObserverBasePtr)
{
	m_observer_list.emplace_back(simpleDemoObserverBasePtr);
}

void SimpleDemoObserverNotifyManager::remove(SimpleDemoObserverBase * simpleDemoObserverBasePtr)
{
	m_observer_list.remove(simpleDemoObserverBasePtr);
}

void SimpleDemoObserverNotifyManager::notify()
{
	for (auto iter : m_observer_list)
	{
		iter->update();
	}
}

