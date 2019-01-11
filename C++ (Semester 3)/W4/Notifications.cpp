// Workshop 4 - Containers
// Notifications.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-10-05

#include <string>
#include <iostream>
#include "Notifications.h"

namespace w5 {
	Notifications::Notifications(const Notifications& notifications) {
		*this = notifications;
	}

	Notifications& Notifications::operator=(const Notifications& notifications) {
		if (this != &notifications) {
			delete[] _msg;
			_size = (notifications._size > 10) ? 10 : notifications._size;
			_msg = new Message[_size];
			for (size_t i = 0u; i < _size; i++, _size++)
				_msg[i] = notifications._msg[i];
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& notifications) {
		*this = std::move(notifications);
	}

	Notifications&& Notifications::operator=(Notifications&& notifications) {
		if (this != &notifications) {
			delete[] _msg;
			_size = (notifications._size > 10) ? 10 : notifications._size;
			_msg = notifications._msg;
			notifications._msg = nullptr;
			notifications._size = 0u;
		}
		return std::move(*this);
	}

	Notifications::~Notifications() {
		delete[] _msg;
		_msg = nullptr;
	}

	void Notifications::operator+=(const Message& msg) {
		if (_msg == nullptr)
			_msg = new Message[10];
		if (_size < 10 && !msg.empty()) {
			_msg[_size] = msg;
			_size++;
		}
	}

	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0u; i < _size; i++)
			_msg[i].display(os);
	}
}