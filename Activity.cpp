//
// Created by erika on 18/11/2021.
//

#include "Activity.h"
#include <string>
#include <iostream>
Activity::Activity(std::string title, Date& date, bool urgent, bool complete) : description(title), date(date), urgent(urgent) {}

const std::string &Activity::getTitle() const {
    return description;
}

void Activity::setTitle(const std::string &title) {
    Activity::description = title;
}

bool Activity::isUrgent() const {
    return urgent;
}

void Activity::setUrgent(bool urgent) {
    Activity::urgent = urgent;
}

const Date& Activity::getDate() const {
    return date;
}

void Activity::setDate(const Date &date) {
    Activity::date = date;
}

//Activity::Activity() {}

/* std::string Activity::getDescription() {

    if (Activity::isUrgent())
        return   Activity::description + "," + Activity::date + ",urgente" ;
    else
        return   Activity::description + "," + Activity::date + ",non urgente" ;

} */

void Activity::setCompleted(bool completed) {
    Activity::completed = completed;
}

bool Activity::isComplete() const {
    return completed;
}

ostream &operator<<(ostream &os, const Activity &activity) {
    if (activity.urgent)
        os <<  activity.description + "," + activity.date.toString() + ",urgente" ;
    else
        os <<  activity.description + "," + activity.date.toString() + ",non urgente" ;

    return os;
}


