// Workshop 5 - Lambda Functions
// Letter.h
// Author: Chaz-Lee Pierre
// Date: 2018-10-10

#pragma once
namespace sict {
	enum class Letter { A_, A, B_, B, C_, C, D_, D, F, X };
	std::string return_value{ '\0' };
	template<typename T>
	const char* convert(const T& t) {
		switch (t) {
		case Letter::A_:
			return_value = "A+";
			break;
		case Letter::A:
			return_value = "A";
			break;
		case Letter::B_:
			return_value = "B+";
			break;
		case Letter::B:
			return_value = "B";
			break;
		case Letter::C_:
			return_value = "C+";
			break;
		case Letter::C:
			return_value = "C";
			break;
		case Letter::D_:
			return_value = "D+";
			break;
		case Letter::D:
			return_value = "D";
			break;
		case Letter::F:
			return_value = "F";
			break;
		default:
			return_value = "X";
			break;
		}
		return return_value.c_str();
	}
}