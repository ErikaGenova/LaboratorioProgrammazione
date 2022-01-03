//
// Created by erika on 18/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#include <string>

class Activity {
public:
    Activity ();
    Activity(std::string title, std::string date, bool urgent);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    bool isUrgent() const;

    void setUrgent(bool urgent);
    //funzione che ritorna titolo,data,urgenza
    std::string getDescription();

private:
    std::string description;
    std::string date;
    bool urgent;
};


#endif //LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
