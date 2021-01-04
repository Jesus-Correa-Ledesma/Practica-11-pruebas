#include <iostream>
#include <fstream>
#include <regex>

class Rational {
	public:
		Rational() = default;
		Rational(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator} {};

		void Parse(std::string raw_string);

		static Rational Add(Rational rational_1, Rational rational_2);

		static Rational Substract(Rational rational_1, Rational rational_2);

		static Rational Multiply(Rational rational_1, Rational rational_2);

		static Rational Divide(Rational rational_1, Rational rational_2);

		Rational operator-() const;

		friend bool operator==(const Rational &rational_1, const Rational &rational_2);
		
		friend bool operator!=(const Rational &rational_1, const Rational &rational_2);

		friend bool operator>(const Rational &rational_1, const Rational &rational_2);

		friend bool operator<(const Rational &rational_1, const Rational &rational_2);

		friend void operator>>(std::string& raw, Rational &output);
		
		friend std::ostream& operator<<(std::ostream& stream, const Rational &rational);

		std::string ToString() const;

	private:
		int numerator_;
		int denominator_;
};