#ifndef IEVENTLISTENER_H
#define IEVENTLISTENER_H

#include "Events.h"
#include "IEvent.h"

class IEventListener
{
public:
	virtual ~IEventListener() { }

	virtual const char *GetName() const = 0;

	virtual bool HandleEvent(const EventPTR &evt) = 0;
};

#endif // !IEVENTLISTENER_H