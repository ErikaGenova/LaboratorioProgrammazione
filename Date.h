//
// Created by erika on 23/01/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_DATE_H
#define LABORATORIOPROGRAMMAZIONE_DATE_H
#include <iostream>
#include <stdexcept>

enum Month{
    Gennaio, Febbraio, Marzo, Aprile, Maggio, Giugno, Luglio, Agosto, Settembre, Ottobre, Novembre, Dicembre
};

class Date {
public:
    Date();
    Date(int day, Month month, int year);
    explicit Date(const std::string& str);

    int getYear() const;
    Month getMonth() const;
    int getDay() const;

    void setYear (int y);
    void setMonth(Month m);
    void setDay(int d);

    std::string toString() const;


private:
    int day;
    Month month;
    int year;
    static bool checkDate(int newDay, Month newMonth, int newYear);
};


#endif //LABORATORIOPROGRAMMAZIONE_DATE_H
