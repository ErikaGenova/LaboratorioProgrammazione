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
    //add list
    void addList(std::string title);
    List getList(int index);

    // view list
    void printLists();
    //delete list
    void deleteList(int index);

    const std::vector<List> &getFullCollection() const;

private:
    std::vector<List> fullCollection;

};


#endif //LABORATORIOPROGRAMMAZIONE_COLLECTIONLISTS_H
