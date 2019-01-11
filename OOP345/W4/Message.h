// Workshop 4 - Containers
// Message.h
// Author: Chaz-Lee Pierre
// Date: 2018-10-05

#pragma once

namespace w5 {
	class Message {
		std::string _user;
		std::string _reply;
		std::string _tweet;
	public:
		Message() : _user{ "" }, _reply{ "" }, _tweet{ "" } {} // safe empty state
		Message(std::ifstream& in, char c); // parse message constructor
		bool empty() const; // check if in safe empty state
		void display(std::ostream& os) const; // display formatted message
	};
}