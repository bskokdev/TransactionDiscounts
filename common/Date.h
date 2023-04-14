#ifndef TRANSACTIONDISCOUNTS_DATE_H
#define TRANSACTIONDISCOUNTS_DATE_H

#include <ostream>

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
     * @brief Constructor for Date
     * @param day
     * @param month
     * @param year
     */
    Date(int day, int month, int year);

    /**
     * @brief Returns month and year in format MM-YYYY
     * @return month and year in format MM-YYYY
     */
    std::string getMonthYear() const;

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
