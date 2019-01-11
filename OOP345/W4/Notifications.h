// Workshop 4 - Containers
// Notifications.h
// Author: Chaz-Lee Pierre
// Date: 2018-10-05

#pragma once
#include "Message.h"

namespace w5 {
	class Notifications {
		Message *_msg; // pointer to array of Messages
		size_t _size; // size of array
	public:
		Notifications() : _msg{ nullptr }, _size{ 0u } {} // safe empty state
		Notifications(const Notifications& notifications); // copy constructor
		Notifications& operator=(const Notifications& notifications); // copy assignment operator
		Notifications(Notifications&& notifications); // move constructor
		Notifications&& operator=(Notifications&& notifications); // move assignment operator
		~Notifications(); // destructor
		void operator+=(const Message& msg); // += overloaded operator
		void display(std::ostream& os) const; // print out Messages in _msg array
	};
}