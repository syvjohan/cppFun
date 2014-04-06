#ifndef EVENTMANGER_H
#define EVENTMANGER_H

#include "Events.h"
#include "IEvent.h"
#include <vector>
#include <map>

class IEventListener;

class EventManager
{
public:

	static void PushEvent(EventPTR evt);
	static void PopEvent(Event evt, bool allOfType = false);

	static void RegisterListener(Event evt, IEventListener *listener);
	static void UnRegisterListener(Event evt, IEventListener *listener);

	static void HandleEvents();

	static void ClearAll();

private:
	static std::vector<EventPTR> _activeEvents;
	static std::vector<EventPTR> _eventQueue;

	// HashTable med en vektor av listeners på varje event.
	static std::map<Event, std::vector<IEventListener*>> _listeners;
};

#endif //!EVENTMANGER_H