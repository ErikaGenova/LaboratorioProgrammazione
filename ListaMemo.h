//
// Created by erika on 20/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LISTAMEMO_H
#define LABORATORIOPROGRAMMAZIONE_LISTAMEMO_H
#include <list>
#include <string>
#include "Promemoria.h"

class ListaMemo {
public:
    ListaMemo(const std::string &titolo);

    void addActivity(Promemoria* p);
    void removeActivity(Promemoria* p);

    const std::string &getTitolo() const;

    void setTitolo(const std::string &titolo);

private:
    std::list<Promemoria*> memo;
    std::string titolo;

};


#endif //LABORATORIOPROGRAMMAZIONE_LISTAMEMO_H
