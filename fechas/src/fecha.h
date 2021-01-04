#include <iostream>
#include <vector>

class Date {
	public:
		//Date = default;
		Date(int day, int month, int year);

		friend std::ostream& operator<<(std::ostream &out, const Date &date);

		void NextDate();

		int day() const;
		int month() const;
		int year() const;
		
	private:
		int day_ = 1;
		int month_ = 1;
		int year_ = 1997;
		const std::vector<int> kDays_by_month_ = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		bool isLeap() const;
};