#ifndef __I_COMPONENT_H_
#define __I_COMPONENT_H_

#include <windows.h>

typedef GUID COM_GUID;

static const int COM_ID_BASE = 10001;

class IComponent
{
public:
	virtual ~IComponent() = default;

public:

	virtual int initialize() = 0;
	virtual int start() = 0;
	virtual int stop() = 0;
	virtual int clear() = 0;

	static const int& getComponentGuid()
	{
		return COM_ID_BASE;
	}
};

#endif


