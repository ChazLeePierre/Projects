// Workshop 5 - Lambda Functions
// Grades.h
// Author: Chaz-Lee Pierre
// Date: 2018-10-10

#pragma once
namespace sict {
	class Grades {
		std::string* _students;
		double* _grades;
		size_t _size = 0u;
	public:
		template<typename F>
		void displayGrades(std::ostream& os, F f) const {
			for (int i = 0; i < _size; i++) {
				auto letter = f(_grades[i]);
				os.precision(2);
				os << "   " << _students[i].c_str() << " " << std::fixed << _grades[i] << " ";
				os.width(4);
				os << std::left << convert(letter) << std::endl;
			}
		}
		Grades() : _students{ nullptr }, _grades{ nullptr }, _size{ 0u } {}
		Grades(const char*);
		~Grades();
		// copying, moving and assigning of a Grades object is prohibited.
		Grades(const Grades&) = delete;
		Grades& operator=(const Grades&) = delete;
		Grades(Grades&&) = delete;
		Grades& operator=(Grades&&) = delete;
	};

}