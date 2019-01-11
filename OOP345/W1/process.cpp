// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-09-06

#include <iostream>
#include "CString.h"

void process(const char* proc_string, std::ostream& os) {
	w1::CString output(proc_string); 
	os << output << std::endl;
}