//
// Created by erika on 18/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#include <string>

using namespace std;

class Activity {
public:
    Activity ();
    Activity(std::string title, std::string date, bool urgent);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    bool isUrgent() const;

    void setUrgent(bool urgent);

    //funzione che ritorna titolo,data,urgenza
    string getDescription();

private:
    std::string description;
    std::string date;
    bool urgent;
};


#endif //LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
