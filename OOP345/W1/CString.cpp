// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// CString.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-09-06
#include "CString.h"

int STORED = w1::CString::_MAXCHAR; // Global

namespace w1 {
	CString::CString(const char* cstring) {
		if (cstring != '\0') {
			const int cstring_length = strlen(cstring); // Define argument (cstring) length
			const int _cstring_length = (cstring_length > _MAXCHAR) ? _MAXCHAR : cstring_length; // Define object (_cstring) length
			/* We want to only capture the max amount of characters, but what if cstring length is less than _MAXCHAR? We don't need to allocate the extra memory if it's not needed. */
			_cstring = new char[_cstring_length + 1];
			strncpy(_cstring, cstring, _cstring_length);
			_cstring[_cstring_length] = '\0';
		}
		else
			_cstring = '\0';
	}

	void CString::display(std::ostream& os) const {
		os << _cstring; 
	}

	std::ostream& operator<<(std::ostream& os, const CString& cstring_OBJ) {
		static int no_of_insertion = 0; // Count the number of insertions
		os << no_of_insertion << ": "; 
		cstring_OBJ.display(os);
		no_of_insertion++;
		return os;
	}

	CString::~CString() {
		delete[] _cstring;
		_cstring = nullptr;
	}
}