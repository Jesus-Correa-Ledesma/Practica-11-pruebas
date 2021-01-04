#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include "rational.h"

Rational Rational::Add(Rational rational_1, Rational rational_2) {
	int denominator = rational_1.denominator_ * rational_2.denominator_;
	
	int numerator = rational_1.numerator_ * rational_2.denominator_;
	numerator += rational_2.numerator_ * rational_1.denominator_;
	
	Rational result = Rational(numerator, denominator);

	return result;
};

Rational Rational::Substract(Rational rational_1, Rational rational_2) {
	return Add(rational_1, -rational_2);
};

Rational Rational::Multiply(Rational rational_1, Rational rational_2) {
	int numerator = rational_1.numerator_ * rational_2.numerator_;
	int denominator = rational_1.denominator_ * rational_2.denominator_;
	
	Rational result = Rational(numerator, denominator);

	return result;
};

Rational Rational::Divide(Rational rational_1, Rational rational_2) {
	Rational inverted = Rational(rational_2.denominator_, rational_2.numerator_);
	
	return Multiply(rational_1, inverted);
};

Rational Rational::operator-() const {
	Rational result = Rational(-numerator_, denominator_);

	return result;
};

bool operator==(const Rational &rational_1, const Rational &rational_2) {
	int numerator_1 = rational_1.numerator_ * rational_2.denominator_;
	int numerator_2 = rational_2.numerator_ * rational_1.denominator_;

	return numerator_1 == numerator_2;
}

bool operator!=(const Rational &rational_1, const Rational &rational_2) {
	return !(&rational_1 == &rational_2);
}

bool operator>(const Rational &rational_1, const Rational &rational_2) {
	int numerator_1 = rational_1.numerator_ * rational_2.denominator_;
	int numerator_2 = rational_2.numerator_ * rational_1.denominator_;

	return numerator_1 > numerator_2;
}

bool operator<(const Rational &rational_1, const Rational &rational_2) {
	return !(&rational_1 > &rational_2) && (&rational_1 != &rational_2);
}

void operator>>(std::string& raw, Rational &output) {
	if (!(std::regex_match(raw, std::regex("[0-9]/[0-9]")))) {
		throw "Parsing error";
	}

	output.numerator_ = std::atoi(&raw[0]);
	int denominator = std::atoi(&raw[2]);

	if (denominator == 0) {
		throw "Denominator must not be 0";
	}

	output.denominator_ = denominator;

	if (denominator < 0) {
		output.numerator_ *= -1;
		output.denominator_ *= -1;
	}
};

std::ostream& operator<<(std::ostream &stream, const Rational &rational) {
	return stream << rational.ToString();
}

std::string Rational::ToString() const {
	std::stringstream out;
	out << numerator_ << "/" << denominator_;
	
	return out.str();
}
