//
// Created by erika on 23/01/2022.
//

#include "Date.h"

Date::Date() : day(01), month(Month::Gennaio), year(1950) {

}

int Date::getYear() const {
    return year;
}

Month Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::setYear(int y) {
    checkDate(day, month, y);
    year = y;
}

void Date::setMonth(Month m) {
    checkDate(day, m, year);
    month = m;
}

void Date::setDay(int d) {
    checkDate(d, month, year);
    day = d;
}

std::string Date::toString() const {
    std::string day = std::to_string(this->day);
    std::string month = std::to_string(this->month + 1);
    std::string year = std::to_string((this->year));

    return day + "/" + month + "/" + year;
}

Date::Date(int day, Month month, int year) {
    checkDate(day, month, year);
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const std::string &str) {
    std::string line = str;
    std::string strDay, strMonth, strYear;
    strDay = line.substr(0, line.find('/'));
    line.erase(0, line.find('/') + 1);
    strMonth = line.substr(0, line.find('/'));
    line.erase(0, line.find('/') + 1);
    strYear = line.substr(0, 4);
    int intDay = std::stoi(strDay);
    int intMonth = std::stoi(strMonth) - 1;
    int intYear = std::stoi(strYear);
    day = intDay;
    month = static_cast<Month>(intMonth);
    year = intYear;
}

bool Date::checkDate(int newDay, Month newMonth, int newYear) {

    if (newDay <= 0)
        throw std::out_of_range("La data non può essere negativa. Immettere un giorno >= 01");

    if (newYear < 1950)
        throw std::out_of_range("Scrivere un anno > 1950");

    if (newMonth == Month::Novembre || newMonth == Month::Aprile || newMonth == Month::Giugno ||
        newMonth == Month::Settembre) {
        if (newDay <= 30)
            return true;
        else
            throw std::out_of_range("Il mese inserito non ha più di 30 giorni");
    } else if (newMonth == Month::Febbraio) {
        if ((newYear % 400) == 0 || (newYear % 4) == 0 && (newYear % 100) != 0) {
            if (newDay <= 29)
                return true;
            else
                throw std::out_of_range("Febbraio negli anni bisestili ha un massimo di 29 giorni");
        } else {
            if (newDay <= 28)
                return true;
            else
                throw std::out_of_range("Febbraio ha un massimo di 28 giorni in un anno normale");
        }

    } else {
        if (newDay <= 31)
            return true;
        else
            throw std::out_of_range("Il mese inserito ha un massimo di 31 giorni");
    }

}
