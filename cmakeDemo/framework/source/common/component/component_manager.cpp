#include "component_manager.h"


FRAMEWORK_COMMON_API IComponentManager* getComponentManager()
{
	static ComponentManager g_componentManager;
	return (&g_componentManager);
}

int ComponentManager::registerComponent(const int& id, IComponent* componentPtr)
{
	comPair* pCom = nullptr;

	comPair* pItem = new comPair;

	pItem->componentID = id;
	pItem->componentPtr = componentPtr;

	m_components.push_back(pItem);

	return 0;
}

int ComponentManager::unRegisterComponent(const int& id)
{
	if (!m_components.empty())
	{
		m_components.clear();
	}
	return 0;
}

int ComponentManager::getComponent(const int& id, OUT IComponent* &componentPtr) const
{
	comPair* pCom = nullptr;
	ComVector::const_iterator it = m_components.begin();
	for (; it != m_components.end(); ++it)
	{
		if (id == (*it)->componentID)
		{
			componentPtr = (*it)->componentPtr;
			return 0;
		}	
	}
	return -1;
}