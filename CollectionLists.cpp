//
// Created by erika on 30/12/2021.
//

#include "CollectionLists.h"
#include <stdexcept>

void CollectionLists::addList(std::string title) {
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

void CollectionLists::editList(int index, List oList) {
    fullCollection.at(index) = oList;
}

void CollectionLists::addList(List oList) {
    fullCollection.push_back(oList);
}
