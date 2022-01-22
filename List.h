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

    Activity getActivity(int index);
    void addActivity(Activity p);
    void editActivity(int index, string newTitle, string newDate, bool newUrgent);
    void removeActivity(int num);
    void cleanList();

    int listActivities() const;
    int countActivities();

    const std::string &getTitolo() const;

    void setTitolo(const std::string &titolo);

    void urgentList() const;

    //cerca attività in base al titolo
    bool findActivity ( const std::string title);

    friend std::ostream &operator<<(std::ostream &os, const List &list);

private:
    std::vector<Activity> memo;
    std::string titolo;

};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
