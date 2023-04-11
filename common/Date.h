#ifndef TRANSACTIONDISCOUNTS_DATE_H
#define TRANSACTIONDISCOUNTS_DATE_H

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

    // Getters and setters
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);
};


#endif //TRANSACTIONDISCOUNTS_DATE_H
