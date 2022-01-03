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

    void listActivities() const;
    int countActivities();

    const std::string &getTitolo() const;

    void setTitolo(const std::string &titolo);

    void urgentList() const;

    friend std::ostream &operator<<(std::ostream &os, const List &list);

private:
    std::vector<Activity> memo;
    std::string titolo;
    std::string temp;

};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
