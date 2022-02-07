//
// Created by erika on 18/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIOPROGRAMMAZIONE_ACTIVITY_H

#include <string>
#include <ostream>
#include "Date.h"

using namespace std;

class Activity {
public:
    Activity() = default;

    Activity(const std::string& title, const Date& date, bool urgent, bool complete = false);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const Date& getDate() const;

    void setDate(const Date &date);

    bool isUrgent() const;

    void setUrgent(bool urgent);

    //funzione attività completata
    void setCompleted(bool completed);
    bool isComplete() const;

    friend ostream &operator<<(ostream &os, const Activity &activity);

private:
    std::string description{"Promemoria"};
    Date date{1,Gennaio, 2022};
    bool urgent = false;
    bool completed = false;
};


#endif //LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
