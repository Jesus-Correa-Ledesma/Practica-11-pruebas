
#include <iostream>
#include <vector>
#include "fecha.h"

Date::Date(int day, int month, int year) : day_{day}, month_{month}, year_{year} {};

std::ostream& operator<<(std::ostream &out, const Date &date) {
	return out << date.day() << "/" << date.month() << "/" << date.year();
}

void Date::NextDate() {
	if (day_ == kDays_by_month_[month_ - 1]) {
		if (isLeap() && month_ == 2) {
			++day_;
		} else {
			day_ = 1;

			if (month_ == 12) {
				month_ = 1;
				++year_;
			} else {
				++month_;
			}
		}
	} else if (month_ == 2 && day_ == 29) {
		day_ = 1;
		++month_;
	} else {
		++day_;
	}
};

int Date::day() const { return day_; };

int Date::month() const { return month_; };

int Date::year() const { return year_; };

bool Date::isLeap() const {
	if ((!(year_ % 100 == 0) || year_ % 400 == 0) && year_ % 4 == 0) {
		return true;
	}
	return false;
};