// Workshop 3 - Templates
// List.h
// Author: Chaz-Lee Pierre
// Date: 2018-09-26

#pragma once
template<typename T, int N>
class List {
	T _List[N];
	size_t count;
public:
	List() : count{ 0 } { }
	size_t size() const { return count; }
	const T& operator[](int index) const { return _List[index]; }
	void operator+=(const T& t) {
		if (count < (sizeof(_List) / sizeof(T))) {
			_List[count] = t;
			count++;
		}
	}
};