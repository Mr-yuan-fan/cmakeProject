#ifndef __COMPONENT_MANAGER_H__
#define __COMPONENT_MANAGER_H__


#include <vector>

#include "i_component_manager.h"

class FRAMEWORK_COMMON_API ComponentManager: public IComponentManager
{
public:
	ComponentManager() {};
	~ComponentManager() {};

public:

	 int registerComponent(const int& id, IComponent* componentPtr) override;

	 int unRegisterComponent(const int& id) override;

	 int getComponent(const int& id, OUT IComponent* &componentPtr) const override;

private:
	struct comPair
	{
		int     componentID;
		IComponent*  componentPtr;
	};

	typedef std::vector<comPair*> ComVector;
	ComVector m_components;

};


#endif 