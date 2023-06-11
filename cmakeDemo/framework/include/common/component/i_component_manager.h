#ifndef __I_COMPONENT_MANAGER_H__
#define __I_COMPONENT_MANAGER_H__

#include "i_component.h"
#include "common.h"

class FRAMEWORK_COMMON_API IComponentManager
{
public:
	IComponentManager() {};
	virtual ~IComponentManager() {};

public:

	virtual int registerComponent(const int& id, IComponent* componentPtr) = 0;

	virtual int unRegisterComponent(const int& id) = 0;

	virtual int getComponent(const int& id, OUT IComponent* &componentPtr) const = 0;

	template <class T>
	int getComponent(OUT T* &componentPtr)
	{
		return getComponent(T::getComponentGuid(), (IComponent* &)componentPtr);
	}
};

//µ¼³ö 
FRAMEWORK_COMMON_API IComponentManager* getComponentManager();

template<typename T>
T* getComponent()
{
	IComponentManager* componentMgr = getComponentManager();

	if (nullptr == componentMgr)
	{
		return nullptr;
	}

	T* componentPtr = nullptr;
	componentMgr->getComponent<T>(componentPtr);

	return componentPtr;
}

inline IComponent* getComponent(const int& id)
{
	IComponentManager* componentMgr = getComponentManager();
	if (nullptr == componentMgr)
	{
		return nullptr;
	}

	IComponent* componentPtr = nullptr;
	componentMgr->getComponent(id, componentPtr);

	return componentPtr;
}


#endif 