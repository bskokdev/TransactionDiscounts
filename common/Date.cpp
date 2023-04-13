#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}

std::string Date::getMonthYear() const {
    return std::to_string(this->month) + "-" + std::to_string(this->year);
}
