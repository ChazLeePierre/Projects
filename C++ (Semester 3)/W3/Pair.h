// Workshop 3 - Templates
// Pair.h
// Author: Chaz-Lee Pierre
// Date: 2018-09-26

#pragma once
template<typename A, typename B>
class Pair {
	A _key;
	B _value;
public:
	Pair() {} // _key and _value are both template variables - should not initialize
	Pair(const A& key, const B& value) { _key = key; _value = value; }
	const A& getKey() const { return _key; }
	const B& getValue() const { return _value; }
};