//
// Created by erika on 18/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_PROMEMORIA_H
#define LABORATORIOPROGRAMMAZIONE_PROMEMORIA_H
#include <string>

class Promemoria {
public:
    Promemoria(std::string descr, std::string date, bool urgent);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    bool isUrgent() const;

    void setUrgent(bool urgent);

private:
    std::string description;
    std::string date;
    bool urgent;
};


#endif //LABORATORIOPROGRAMMAZIONE_PROMEMORIA_H
