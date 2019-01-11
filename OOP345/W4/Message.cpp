// Workshop 4 - Containers
// Message.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-10-05

#include <iostream>
#include <string>
#include <fstream>
#include "Message.h"

namespace w5 {
	Message::Message(std::ifstream& in, char c) {
		std::string buffer;
		std::getline(in, buffer, c);
		for (size_t count = 0u, position = 0u; (position = buffer.find(' ')) != std::string::npos; count++, buffer.erase(0, position + 1)) { 
			if (count == 0u) 
				_user = buffer.substr(0, position);
			else if (count == 1u) {
				if (buffer.substr(0, 1) == "@")
					_reply = buffer.substr(1, position - 1);
				else {
					_tweet = buffer;
					return;
				}
			} else {
				_tweet = buffer;
				return;
			}
		}
	}

	bool Message::empty() const {
		return _user.empty() && _reply.empty() && _tweet.empty();
	}

	void Message::display(std::ostream& os) const {
		if (!_tweet.empty()) {
			os << "Message" << std::endl
			<< " User  : " << _user << std::endl;
			if (!_reply.empty()) os << " Reply : " << _reply << std::endl;
			os << " Tweet : " << _tweet << std::endl << std::endl;
		}
	}
}