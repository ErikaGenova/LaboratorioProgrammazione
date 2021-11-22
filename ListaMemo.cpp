//
// Created by erika on 20/11/2021.
//

#include "ListaMemo.h"

ListaMemo::ListaMemo(const std::string &titolo) : titolo(titolo) {}

const std::string &ListaMemo::getTitolo() const {
    return titolo;
}

void ListaMemo::setTitolo(const std::string &titolo) {
    ListaMemo::titolo = titolo;
}

void ListaMemo::addActivity(Promemoria *p) {
    memo.push_back(p);
}

void ListaMemo::removeActivity(Promemoria *p) {
    memo.remove(p);
}
