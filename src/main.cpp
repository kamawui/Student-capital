#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include "string_utilities.h"

struct Laptop {
	int64_t price;
	int64_t gain;
};

int64_t parseInteger(std::string& src) {
	trim(src);
	std::stringstream ss(src);
	int64_t value;

	if (!(ss >> value) || !ss.eof()) {
		throw std::runtime_error("Invalid argument entered: " + src);
	}

	return value;
}

std::vector<int64_t> parseIntegerVector(std::string& src) {
	std::stringstream ss(src);
	std::vector<int64_t> v;
	std::string temp;

	while (ss >> temp) {
		int64_t value = parseInteger(temp);
		v.push_back(value);
	}

	return v;
}

bool lessPrice(const Laptop& l1, const Laptop& l2) {
	return l1.price < l2.price;
}

class greaterProfit {
public:
	bool operator()(const Laptop& l1, const Laptop& l2) {
		return (l1.gain - l1.price) < (l2.gain - l2.price);
	}
};

int main() {
	try {
		std::cout << "Enter number of laptops N to buy: ";
		std::string N;
		std::getline(std::cin, N);
		int64_t laptops_number = parseInteger(N);

		std::cout << "Enter capital amount C: ";
		std::string C;
		std::getline(std::cin, C);
		int64_t capital_amount = parseInteger(C);

		std::cout << "Enter laptops gains array: ";
		std::string gains;
		std::getline(std::cin, gains);
		std::vector<int64_t> gains_array = parseIntegerVector(gains);

		std::cout << "Enter laptops price array: ";
		std::string price;
		std::getline(std::cin, price);
		std::vector<int64_t> price_array = parseIntegerVector(price);

		if (gains_array.size() != price_array.size()) {
			throw std::runtime_error("gains and prices arrays have different lengths.");
		}

		std::vector<Laptop> laptops;

		for (size_t i = 0; i < gains_array.size(); i++) {
			if (gains_array[i] > price_array[i]) {
				laptops.push_back(Laptop{ price_array[i], gains_array[i] });
			}
		}

		std::sort(laptops.begin(), laptops.end(), lessPrice);

		std::priority_queue<Laptop, std::vector<Laptop>, greaterProfit> profit_laptops;
		
		size_t currentLaptop = 0;

		for (int64_t fixed = 0; fixed < laptops_number; fixed++) {
			while (currentLaptop < laptops.size() && capital_amount >= laptops[currentLaptop].price) {
				profit_laptops.push(laptops[currentLaptop++]);
			}

			if (profit_laptops.empty()) {
				break;
			}

			capital_amount = capital_amount - profit_laptops.top().price + profit_laptops.top().gain;
			profit_laptops.pop();
		}

		std::cout << "Capital at the end of the summer: " << capital_amount << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error occured. " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cout << "Unexpecte error occured" << std::endl;
		return 2;
	}

	return 0;
}