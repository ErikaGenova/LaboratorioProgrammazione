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
    List getList(std::string title);

    //add list
    void addList(const std::string title); // aggiunge lista vuota con solo titolo
    void addList( const List& oList); // passa lista per referenza

    // edit list
    void editList(int index, const List& oList);

    // view list
    void printLists();

    //delete list
    void deleteList(int index);

    const std::vector<List> &getFullCollection() const;

    //cancella lista in base al titolo
    void deleteList(std::string title);

    //editList in base al titolo
    void editList(std::string title, std::string newTitle);

    //sposta attività da una lista all'altra
    void moveActivity(const std::string& oldList, const std::string& newList,const std::string& title);

private:
    std::vector<List> fullCollection;

};


#endif //LABORATORIOPROGRAMMAZIONE_COLLECTIONLISTS_H
