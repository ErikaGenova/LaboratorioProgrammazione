//
// Created by erika on 18/11/2021.
//

#include "Promemoria.h"
#include <string>
Promemoria::Promemoria(std::string descr, std::string date, bool urgent) {}

const std::string &Promemoria::getDescription() const {
    return description;
}

void Promemoria::setDescription(const std::string &description) {
    Promemoria::description = description;
}

bool Promemoria::isUrgent() const {
    return urgent;
}

void Promemoria::setUrgent(bool urgent) {
    Promemoria::urgent = urgent;
}

const std::string &Promemoria::getDate() const {
    return date;
}

void Promemoria::setDate(const std::string &date) {
    Promemoria::date = date;
}
