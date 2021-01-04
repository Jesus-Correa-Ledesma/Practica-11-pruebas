#include <iostream>
#include <cmath>
#include "complex.h"

Complex Complex::Conjugate() const {
	Complex result = Complex(a_, -b_);
	return result;
};

Complex Complex::Inverse() const {
	Complex conjugate = this->Conjugate();
	return Complex::Multiply(conjugate, Complex(1. / std::pow(a_, 2) + std::pow(b_, 2), 0));
};

void Complex::print() const {
	std::cout << *this << std::endl;
};

Complex Complex::Add(const Complex& complex_1, const Complex& complex_2) {
	double a = complex_1.a_ + complex_2.a_;
	double b = complex_1.b_ + complex_2.b_;
	Complex result = Complex(a, b);
	
	return result;
};

Complex Complex::Sub(const Complex& complex_1, const Complex& complex_2) {
	double a = complex_1.a_ - complex_2.a_;
	double b = complex_1.b_ - complex_2.b_;
	Complex result = Complex(a, b);
	
	return result;
};

Complex Complex::Multiply(const Complex& complex_1, const Complex& complex_2) {
	double a = complex_1.a_ * complex_2.b_ - complex_1.b_ * complex_2.a_;
	double b = complex_2.a_ * complex_1.b_ + complex_2.b_ * complex_1.a_;
	Complex result = Complex(a, b);
	
	return result;
};

Complex Complex::Divide(const Complex& complex_1, const Complex& complex_2) {
	return Complex::Multiply(complex_1, complex_2.Inverse());
};
		
std::ostream& operator<<(std::ostream& stream, const Complex& complex_2) {
	return stream << complex_2.a_ << (complex_2.b_ > 0 ? "+" : "-") << std::abs(complex_2.b_) << "i";
};