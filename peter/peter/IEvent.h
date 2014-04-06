#ifndef IEVENT_H
#define IEVENT_H

#include "Utility.h"
#include "Events.h"
#include <memory>

class IEvent
{
public:
	virtual ~IEvent() {};

	virtual Event Id() const = 0;
	
};

typedef std::shared_ptr<IEvent> EventPTR;


class MoveEvent : public IEvent
{
public:
	MoveEvent(Point dir) : _direction(dir) { }

	Event Id() const { return EVT_MOVE; }
	Point GetDirection() const { return _direction; }
	
private:
	Point _direction;
};

#endif // !IEVENT_H