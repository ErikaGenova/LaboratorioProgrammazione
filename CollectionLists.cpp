//
// Created by erika on 30/12/2021.
//

#include "CollectionLists.h"
#include <stdexcept>

void CollectionLists::addList(const std::string title) {
    List newList(title);
    fullCollection.push_back(newList);
}

void CollectionLists::printLists() {
    int a=0;
    for (auto i: this->fullCollection) {
        std::cout << a << " - " << i.getTitolo() << std::endl;
        a++;
    }
}

CollectionLists::CollectionLists() {
}

List CollectionLists::getList(int index) {
    if (index < 0 || index > fullCollection.size()-1)
        throw std::invalid_argument("Lista non esistente, immettere un numero valido!");
    else

    return fullCollection.at(index);
}

void CollectionLists::deleteList(int index) {
    if (index < 0 || index > fullCollection.size()-1)
        throw std::invalid_argument("Lista non esistente, immettere un numero valido!");
    else

    fullCollection.erase(fullCollection.begin()+index);
}

const std::vector<List> &CollectionLists::getFullCollection() const {
    return fullCollection;
}

void CollectionLists::editList(int index, const List& oList) {
    fullCollection.at(index) = oList;
}

void CollectionLists::addList(const List& oList) {
    fullCollection.push_back(oList);
}

void CollectionLists::deleteList(std::string title) {
    bool found = false;
    int index = 0;
    for (auto i: this->fullCollection){
        if( i.getTitolo()== title) {
            fullCollection.erase(fullCollection.begin() + index);
            found= true;
        }
        index++;
    }

    if (!found)
        throw std::invalid_argument("Non è possibile eliminare questa lista perché non esiste");
}


