#include "EventManager.h"
#include "IEventListener.h"


std::vector<EventPTR> EventManager::_eventQueue;
std::vector<EventPTR> EventManager::_activeEvents;
std::map<Event, std::vector<IEventListener*>> EventManager::_listeners;

void EventManager::PushEvent(EventPTR evt)
{
	_eventQueue.push_back(evt);
}

void EventManager::PopEvent(Event evt, bool allOftype)
{
	for (auto it = _eventQueue.end() - 1; it != _eventQueue.begin() - 1; it--)
	{
		if ((*it)->Id() == evt)
		{
			it = _eventQueue.erase(it);

			if (!allOftype) break;
		}
	}
}

void EventManager::RegisterListener(Event evt, IEventListener *listener)
{
	auto list = _listeners.find(evt);

	// Are we aware of this event from before?
	if (list == _listeners.end())
	{
		// No, so we create the mapping.
		std::vector<IEventListener*> vec;
		vec.push_back(listener);
		_listeners.insert(std::make_pair(evt, vec));
	}
	else
	{
		list->second.push_back(listener);
	}

	printf("Added [%s] to the event[%i].\n", listener->GetName(), evt);
}

void EventManager::UnRegisterListener(Event evt, IEventListener *listener)
{
	auto list = _listeners.find(evt);

	if (list != _listeners.end())
	{
		for (auto it = list->second.begin(); it != list->second.end(); ++it)
		{
			if (*it == listener)
			{
				printf("Removed [%s] from the event[%i].\n", listener->GetName(), evt);
				it = list->second.erase(it);
				break;
			}
		}
	}
}

void EventManager::HandleEvents()
{
	_activeEvents.swap(_eventQueue);

	for (const EventPTR &evt : _activeEvents)
	{
		auto list = _listeners.find(evt->Id());

		if (list != _listeners.end())
		{
			for (IEventListener *listener : list->second)
			{
				if (listener->HandleEvent(evt))
				{
					break;
				}
			}
		}


	}

	_activeEvents.clear();
}

void EventManager::ClearAll()
{
	_eventQueue.clear();
	//_activeEvents.clear();
}

