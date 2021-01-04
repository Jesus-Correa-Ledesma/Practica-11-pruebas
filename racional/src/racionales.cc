#include <iostream>
#include <fstream>
#include <regex>
#include "rational.h"

int main() {
	std::ifstream file("in.txt");
	std::ofstream out_file("out.txt");
	std::string line;

	while (std::getline(file, line)) {
		if (!line.length() && !(std::regex_match(line, std::regex("([0-9]/[0-9][ ][0-9]/[0-9])")))) {
			std::cerr << " Parsing error in input file in line:" << std::endl;
			std::cerr << "      " << line << std::endl;
			return 1;
		}

		Rational rational_1;
		Rational rational_2;

		std::string raw_rational_1 = line.substr(0, 3);
		std::string raw_rational_2 = line.substr(4, 3);

		raw_rational_1 >> rational_1;
		raw_rational_2 >> rational_2;

		out_file << rational_1;
		out_file << " + " << rational_2;
		out_file << " = " << Rational::Add(rational_1, rational_2);
		out_file << '\n';
		
		out_file << rational_1;
		out_file << " - " << rational_2;
		out_file << " = " << Rational::Substract(rational_1, rational_2);
		out_file << '\n';
		
		out_file << rational_2;
		out_file << " - " << rational_1;
		out_file << " = " << Rational::Substract(rational_2, rational_1);
		out_file << '\n';
		
		out_file << rational_1;
		out_file << " * " << rational_2;
		out_file << " = " << Rational::Multiply(rational_1, rational_2);
		out_file << '\n';
		
		out_file << rational_1;
		out_file << " : " << rational_2;
		out_file << " = " << Rational::Divide(rational_1, rational_2);
		out_file << '\n';
		
		out_file << rational_1;
		out_file << " : " << rational_2;
		out_file << " = " << Rational::Divide(rational_2, rational_1);
		out_file << '\n';

		out_file << std::endl;
	}

	out_file.close();
	return 0;
}