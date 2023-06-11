#ifndef __COMPONENT_REGISTER_H__
#define __COMPONENT_REGISTER_H__

#include <assert.h>
#include "i_component_manager.h"

template <typename T>
class ComponentRegister
{
public:

	//void* operator new(size_t size) = delete;
	//void* opetator new(size_t size, void* ptr) = delete;
	//ComponentRegister&  opetator= (const  ComponentRegister&) = delete;

public:
	ComponentRegister(T* componentPtr) :m_componentPtr(componentPtr)
	{
		if (nullptr == componentPtr)
		{
			assert( nullptr != componentPtr);
		}
		else
		{
			IComponentManager* componentMgr = getComponentManager();
			if (nullptr == componentMgr)
			{
				assert(nullptr != componentMgr);
			}
			else
			{
				int ret = componentMgr->registerComponent(m_componentPtr->getComponentGuid(), componentPtr);
				assert(0 ==  ret);
			}
		}
	}

	~ComponentRegister()
	{
		if (nullptr != m_componentPtr)
		{
			IComponentManager* componentMgr = getComponentManager();
			if (nullptr == componentMgr)
			{
				assert(nullptr != componentMgr);
			}
			else
			{
				int ret = componentMgr->unRegisterComponent(m_componentPtr->getComponentGuid());
				assert(0 == ret);
			}
		}
	}

private:

	T* m_componentPtr;
};

#define COMPONENT_AUTO_REGISTER(className) \
className g_##className##Instance; \
ComponentRegister<className> g_##className##autoRegister(&g_##className##Instance);

#endif