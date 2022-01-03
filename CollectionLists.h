//
// Created by erika on 30/12/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_COLLECTIONLISTS_H
#define LABORATORIOPROGRAMMAZIONE_COLLECTIONLISTS_H
#include <vector>
#include "List.h"
#include <iostream>

class CollectionLists {
public:
    CollectionLists();
    List getList(int index);
    //add list
    void addList(std::string title); // aggiunge lista vuota con solo titolo
    void addList(List oList); // aggiunge lista come oggetto

    // edit list
    void editList(int index, List oList);

    // view list
    void printLists();
    //delete list
    void deleteList(int index);

    const std::vector<List> &getFullCollection() const;

private:
    std::vector<List> fullCollection;

};


#endif //LABORATORIOPROGRAMMAZIONE_COLLECTIONLISTS_H
