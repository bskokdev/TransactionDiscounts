#include <iomanip>
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
    os << date.getYear() << "-"
       << std::setw(2) << std::setfill('0') << date.getMonth()
       << std::setw(0) << std::setfill(' ') << "-"
       << std::setw(2) << std::setfill('0') << date.getDay();
    return os;
}

std::string Date::getMonthYear() const {
    return std::to_string(this->month) + "-" + std::to_string(this->year);
}

Date Date::buildDateFromString(std::string &dateString) {
    std::vector<std::string> dateTokens = Reader::tokenize(dateString, '-');

    int year = std::stoi(dateTokens[0]);
    int month = std::stoi(dateTokens[1]);
    int day = std::stoi(dateTokens[2]);

    return {day, month, year};
}
