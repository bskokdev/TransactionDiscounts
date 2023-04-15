#ifndef TRANSACTIONDISCOUNTS_DATE_H
#define TRANSACTIONDISCOUNTS_DATE_H

#include <ostream>
#include <string>
#include <vector>
#include "../io/Reader.h"

/**
 * @brief Class representing a date
 */
class Date {
private:
    int day;
    int month;
    int year;
public:

    /**
     * @brief Default constructor for Date
     */
    Date() = default;

    /**
     * @brief Constructor for Date
     * @param day day of the month
     * @param month month of the year
     * @param year
     */
    Date(int day, int month, int year);

    /**
     * @brief Returns month and year in format MM-YYYY
     * @return month and year in format MM-YYYY
     */
    std::string getMonthYear() const;

    /**
     * @brief Build a Date object from a string (format: YYYY-MM-DD)
     * @param dateString string to be converted to Date
     * @return Date object
     */
    static Date buildDateFromString(std::string &dateString);

    /**
     * @brief Checks if a string is a valid date
     * @param dateString string to be checked (format: YYYY-MM-DD)
     * @return true if string is a valid date
     */
    static bool isStringValidDate(std::string &dateString);

    static bool isLeapYear(int &year);

    // Getters and setters
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    // operators
    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};


#endif //TRANSACTIONDISCOUNTS_DATE_H
