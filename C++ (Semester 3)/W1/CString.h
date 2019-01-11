// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// CString.h
// Author: Chaz-Lee Pierre
// Date: 2018-09-06

#pragma once
#include <iostream>
#include <cstring>

namespace w1 {
	class CString {
	public:
		static const int _MAXCHAR = 3;
	private:
		char* _cstring = '\0';
	public:
		CString(const char* cstring);
		void display(std::ostream& os) const;
		~CString();
	};
	std::ostream& operator<<(std::ostream& os, const CString& cstring_OBJ);
}