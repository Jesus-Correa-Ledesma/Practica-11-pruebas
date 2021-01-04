#include <iostream>

class Complex {
	public:
		Complex() = default;
		Complex(double a, double b) : a_{a}, b_{b} {};

		Complex Conjugate() const;

		Complex Inverse() const;

		void print() const;

		static Complex Add(const Complex& complex_1, const Complex& complex_2);

		static Complex Sub(const Complex& complex_1, const Complex& complex_2);
		
		static Complex Multiply(const Complex& complex_1, const Complex& complex_2);
		
		static Complex Divide(const Complex& complex_1, const Complex& complex_2);
				
		friend std::ostream& operator<<(std::ostream& stream, const Complex& complex_2);

	private:
		double b_;
		double a_;
};