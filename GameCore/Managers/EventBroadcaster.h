#pragma once
#ifndef GAMECORE_EVENT_BROADCASTER_HPP
#define GAMECORE_EVENT_BROADCASTER_HPP

#include "../../BaseClasses/Enums/EventKey.h"
#include "../../Entities/Components/Script/EventListener.h"

namespace gamecore {

    using namespace interfaces;

    class EventBroadcaster
	{
	private:
		std::unordered_map<EventKey, std::vector<EventListener*>> mapListener;
		std::vector<EventListener*> vecListener;

	public:

		void RegisterListener(EventListener* listener);
		void UnregisterListener(EventListener* pListener);
		void UnregisterAllListeners();
		void Broadcast(EventKey key, std::unordered_map<std::string, void*> mapParameter = {});

	private:
		int FindListener(EventListener* pListener, std::vector<EventListener*> vecListener = {});

		/* * * * * * * * * * * * * * * * * * * * *
		 *       SINGLETON-RELATED CONTENT       *
		 * * * * * * * * * * * * * * * * * * * * */
	private:
		static EventBroadcaster* Instance;

	private:
		EventBroadcaster() {}
		EventBroadcaster(const EventBroadcaster&) = delete;
		EventBroadcaster& operator= (const EventBroadcaster&) = delete;

	public:
		static EventBroadcaster* GetInstance();
		/* * * * * * * * * * * * * * * * * * * * */
	};
}

#endif