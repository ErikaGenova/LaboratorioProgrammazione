//
// Created by erika on 20/11/2021.
//

#include "List.h"
#include <iostream>

List::List(const std::string &titolo) : titolo(titolo) {}

const std::string &List::getTitolo() const {
    return titolo;
}

void List::setTitolo(const std::string &titolo) {
    List::titolo = titolo;
}

void List::addActivity(Activity p) {
    memo.push_back(p);
}

void List::removeActivity(int num) {
    if (num < 0 || num > memo.size()-1)
        throw std::invalid_argument("Lista non esistente, immettere un numero valido!");
    else
    memo.erase(memo.begin()+num);
}

std::ostream &operator<<(std::ostream &os, const List &list) {
    os << list.titolo << std::endl;
    for (auto i: list.memo)
        os << "Memo: " << i.getTitle() << std::endl;
    return os;
}

//stampa attività urgenti
void List::urgentList() const {
    for (auto i: this->memo )
        if (i.isUrgent())
            std::cout << i.getTitle() << std::endl;

}

//stampa tutte le attività nella lista
void List::listActivities() const {
    int a=0;
    for (auto i: this->memo) {
        std::cout << a << " - " << i.getDescription() << std::endl;
        /*if (i.isUrgent())
            std::cout << a << " - " << i.getTitle() << ", " << i.getDate() << ", urgente" << std::endl;
        else
            std::cout << a << " - " << i.getTitle() << ", " << i.getDate() << ", non urgente" << std::endl;
*/
        a++;

    }
}

//conta attività nella lista
int List::countActivities() {
    int count=0;
    for (auto i: this->memo)
        count++;
    std::cout << count << std::endl;

    return count;
}

Activity List::getActivity(int index) {
    return memo.at(index);
}

List::List() {

}

void List::editActivity(int index, string newTitle, string newDate, bool newUrgent) {
    memo.at(index).setTitle(newTitle);
    memo.at(index).setDate(newDate);
    memo.at(index).setUrgent(newUrgent);
}
