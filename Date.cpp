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
    if (y < 1950)
        throw std::out_of_range("Scrivere un anno > 1950");
    else
        year = y;
}

void Date::setMonth(Month m) {
    month = m;
}

void Date::setDay(int d) {
    if (d <= 0)
        throw std::out_of_range("La data non può essere negativa. Immettere un giorno >= 01");

    if (month == Month::Novembre || month == Month::Aprile || month == Month::Giugno || month == Month::Settembre) {
        if (d > 30)
            throw std::out_of_range("Questo mese ha un massimo di 30 giorni");
        else
            day = d;
    }

    if (month == Month::Febbraio) {
        if ((year % 400) == 0 || (year % 4) == 0 && (year % 100) != 0) {
            if (d > 29)
                throw std::out_of_range("Febbraio ha un massimo di 29 giorni in un anno bisestile");
            else
                day = d;
        } else {
            if (d > 28)
                throw std::out_of_range("Febbraio ha un massimo di 28 giorni in un anno normale");
            else
                day = d;
        }

    }

    if (month == Month::Gennaio || month == Month::Marzo || month == Month::Maggio || month == Month::Luglio ||
        month == Month::Agosto || month == Month::Ottobre || month == Month::Dicembre) {
        if (d > 31)
            throw std::out_of_range("Questo mese ha un massimo di 31 giorni");
        else
            day = d;
    }
}

std::string Date::toString() const {
    std::string day = std::to_string(this->day);
    std::string month = std::to_string(this->month + 1);
    std::string year = std::to_string((this->year));

    return day + "/" + month + "/" + year;
}

Date::Date(int day, Month month, int year) : day(day), month(month), year(year) {

}

Date::Date(std::string str) {
    std::string line = str;
    std::string strDay, strMonth, strYear;
    strDay = line.substr(0, line.find('/'));
    line.erase(0, line.find('/') + 1);
    strMonth = line.substr(0, line.find('/'));
    line.erase(0, line.find(',') + 1);
    strYear = line.substr(0, 3);
    int intDay = std::stoi(strDay);
    int intMonth = std::stoi(strMonth) - 1;
    int intYear = std::stoi(strYear);
}
