//
// Created by erika on 20/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LIST_H
#define LABORATORIOPROGRAMMAZIONE_LIST_H
#include <vector>
#include <string>
#include <stdexcept>
#include "Activity.h"
#include <ostream>

class List {
public:
    List();
    List(const std::string &titolo);

    Activity getActivity(int index) const;
    Activity getActivity(const std::string& title) const;
    void addActivity(const Activity& p);
    void editActivity(int index, const string& newTitle, Date& newDate, bool newUrgent, bool newCompleted);
    void removeActivity(int num);
    void removeActivity(std::string title);
    void cleanList();

    int listActivities() const;
    int countActivities() const;

    const std::string &getTitle() const;

    void setTitle(const std::string &titolo);

    void urgentList() const;

    //quante sono le attività urgenti
    int howManyUrgent() const;

    //quante sono le attività DA COMPLETARE
    int howManyCompleted() const;


    //cerca attività in base al titolo
    bool findActivity ( const std::string& title);

    friend std::ostream &operator<<(std::ostream &os, const List &list);

private:
    std::vector<Activity> memo;
    std::string titolo;

};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
