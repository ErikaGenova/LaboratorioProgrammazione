//
// Created by erika on 20/11/2021.
//

#include "List.h"
#include <iostream>

List::List(const std::string &titolo) : titolo(titolo) {}

const std::string &List::getTitle() const {
    return titolo;
}

void List::setTitle(const std::string &titolo) {
    List::titolo = titolo;
}

void List::addActivity(const Activity& p) {
    memo.push_back(p);
}

void List::removeActivity(int num) {
    if (num < 0 || num > memo.size() - 1)
        throw std::invalid_argument("Lista non esistente, immettere un numero valido!");
    else
        memo.erase(memo.begin() + num);
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    os << list.titolo << std::endl;
    for (auto i: list.memo)
        os << "Memo: " << i.getTitle() << std::endl;
    return os;
}

//stampa attività urgenti
void List::urgentList() const {
    for (auto i: this->memo)
        if (i.isUrgent())
            std::cout << i.getTitle() << std::endl;

}

//stampa tutte le attività nella lista
int List::listActivities() const {
    int a = 0;
    for (auto i: this->memo) {
        std::cout << a << " - " << i << std::endl;
        a++;
    }
    //returns a for test
    return a;
}

// conta attività nella lista
int List::countActivities() const {
    return memo.size();
}

Activity List::getActivity(int index) const {
    return memo.at(index);
}

List::List() : titolo("Lista") {

}

void List::editActivity(int index, const string& newTitle, Date& newDate, bool newUrgent, bool newCompleted) {
    memo.at(index).setTitle(newTitle);
    memo.at(index).setDate(newDate);
    memo.at(index).setUrgent(newUrgent);
    memo.at(index).setCompleted(newCompleted);
}

void List::cleanList() {
    memo.erase(memo.begin(), memo.end());
    titolo = "";
}

bool List::findActivity(const std::string& title) {

    for (auto i: this->memo) {
        if (i.getTitle() == title) {
            return true;
        }
    }

    throw std::invalid_argument("Promemoria non esistente");
}

Activity List::getActivity(const std::string& title) const{
    int index = 0;
    for (auto i: this->memo) {
        if (i.getTitle() == title) {
            return memo.at(index);
        }
        index++;
    }
        throw std::invalid_argument("Promemoria non esistente");

}

void List::removeActivity(std::string title) {
    int index = 0;
    for (auto i: this->memo) {
        if (i.getTitle() == title)
            memo.erase(memo.begin() + index);
        index++;
    }
}

int List::howManyUrgent() const {
    int urgent = 0;
    for (auto i: this->memo) {
        if (i.isUrgent())
            urgent++;
    }
    return urgent;
}

int List::howManyCompleted() const {
    int completed = 0;
    for (auto i: this->memo) {
        if (i.isComplete())
            completed++;
    }

    return completed;
}
