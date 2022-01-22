//
// Created by erika on 18/11/2021.
//

#ifndef LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
#define LABORATORIOPROGRAMMAZIONE_ACTIVITY_H

#include <string>

using namespace std;

class Activity {
public:
    Activity() = default;

    Activity(std::string title, std::string date, bool urgent, bool complete = false);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    bool isUrgent() const;

    void setUrgent(bool urgent);

    //funzione che ritorna titolo,data,urgenza
    string getDescription();

    //funzione attività completata
    void setCompleted(bool completed);

private:
    std::string description{"Promemoria"};
    std::string date{"01/01/2022"};
    bool urgent = false;
    bool completed = false;
};


#endif //LABORATORIOPROGRAMMAZIONE_ACTIVITY_H
