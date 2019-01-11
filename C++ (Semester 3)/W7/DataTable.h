// Workshop 7 - STL Algorithms
// DataTable.h
// Author: Chaz-Lee Pierre
// Date: 2018-11-01

#pragma once

#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

namespace w7 {

	template <typename T>
	class DataTable {
		int _width;
		int _precision;
		int _n;
		std::vector<T> _x_coordinates;
		std::vector<T> _y_coordinates;
	public:
		DataTable(std::ifstream& is, int width, int number_of_decimals) { // Initialize
			_width = width;
			_precision = number_of_decimals;
			T x, y;
			while (!is.eof()) {
				is >> x >> y;
				_x_coordinates.push_back(x);
				_y_coordinates.push_back(y);
			}
		}

		T mean() const { // Sample mean | zmean = ( Σizi ) / n
			T sum = std::accumulate(_y_coordinates.begin(), _y_coordinates.end(), static_cast<T>(0.0)); 
			return sum / _y_coordinates.size();
		}

		T sigma() const { // Sample standard deviation | ssd = √{ [ Σi(zi - zmean)2 ] / (n - 1) }
			std::vector<T> temporary(_y_coordinates.size(), static_cast<T>(0.0));
			std::transform(_y_coordinates.begin(), _y_coordinates.end(), temporary.begin(), [&](T i) {
				return std::pow((i - mean()), 2);
			});
			T sum = std::accumulate(temporary.begin(), temporary.end(), static_cast<T>(0.0));
			return std::sqrt(sum / (temporary.size() - 1)); 
		}

		T median() const { // Sample median | median = {(n + 1) ÷ 2}
			std::vector<T> sort_ = _y_coordinates;
			std::sort(sort_.begin(), sort_.end());
			return sort_[_y_coordinates.size() / 2];
		}

		void regression(T& slope, T& y_intercept) const { 
			// Slope = [ n ( Σixiyi ) - Σixi Σiyi ] / [ n (Σixi2) - (Σixi)2 ]
			// Y intercept = [ Σiyi - slope * Σixi ] / n
			T x_mean = std::accumulate(_x_coordinates.begin(), _x_coordinates.end(), static_cast<T>(0.0)) / _x_coordinates.size();
			T y_mean = mean();
			std::vector<T> numerator(_x_coordinates.size(), static_cast<T>(0.0)), denominator(_y_coordinates.size(), static_cast<T>(0.0));
			std::transform(_x_coordinates.begin(), _x_coordinates.end(), _y_coordinates.begin(), numerator.begin(), [&](T x, T y) { 
				return (x - x_mean) * (y - y_mean); 
			});
			std::transform(_x_coordinates.begin(), _x_coordinates.end(), denominator.begin(), [&](T x) { 
				return std::pow(x - x_mean, 2); 
			});
			T numerater_sum = std::accumulate(numerator.begin(), numerator.end(), static_cast<T>(0.0));
			T denominator_sum = std::accumulate(denominator.begin(), denominator.end(), static_cast<T>(0.0));
			slope = numerater_sum / denominator_sum;
			y_intercept = y_mean - (slope * x_mean);
		}

		void display(std::ostream& os) const {
			os << std::setw(_width) << "x" << std::setw(_width) << "y" << std::endl;
			for (size_t i = 0u; i < _x_coordinates.size(); i++) {
				os << std::setw(_width) << std::fixed << std::setprecision(_precision) << _x_coordinates[i];
				os << std::setw(_width) << std::fixed << std::setprecision(_precision) << _y_coordinates[i] << std::endl;
			}
		}
		
		friend std::ostream& operator<<(std::ostream& os, const DataTable& datatable) {
			datatable.display(os);
			return os;
		}
	
	};
}
