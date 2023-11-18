#pragma once
#ifndef INTERFACES_EVENT_LISTENER_HPP
#define INTERFACES_EVENT_LISTENER_HPP

#include <unordered_map>
#include <string>
#include "../../../BaseClasses/Enums/EventKey.h"

namespace interfaces {

	class EventListener {
	public:
		virtual ~EventListener() {}

	public:
		virtual void OnEventTrigger(std::unordered_map<std::string, void*> mapParameter) = 0;
		virtual EventKey GetKey() = 0;
	};
}

#endif