#include <iostream>
#include "Activity.h"
#include "List.h"
#include "CollectionLists.h"
#include <fstream>
#include <vector>
void HandleList(CollectionLists& AllLists, int index);
using namespace std;

int main() {
    std::string titolo, azione;
    CollectionLists toDo;


    while (azione != "Q") {
        std::cout << "[L] Elenco liste - [A] Aggiungi lista - [M] Modifica lista - [S] Salva su file - [R] Leggi da file - [Q] Esci"<< std::endl;
        std::cin >> azione;

        if (azione == "L") {
            toDo.printLists();
        }
        else if (azione == "A") {
            std::cout << "Inserire titolo lista" << std::endl;
            std::cin >> titolo;
            toDo.addList(titolo);
        }
        else if (azione == "M"){
            int num;
            std::cout << "Inserire numero lista" << std::endl;
            std:: cin >> num;
            HandleList(toDo, num);
        }
        else if (azione == "S") {
            std::vector<List> allLists = toDo.getFullCollection();
            fstream myfile;
            myfile.open ("ToDo.txt", ios::out);

            if(myfile.is_open()) {

                for (int i = 0; i < allLists.size(); i++) {
                    List loopList = allLists.at(i);
                    myfile << "<" << loopList.getTitolo() << ">" << std::endl;

                    for (int j = 0; j < loopList.countActivities(); j++) {
                        myfile << " " << loopList.getActivity(j).getDescription() << std::endl;
                    }
                };

                myfile.close();
            }

        }
        else if (azione== "R"){
            std::vector<List> allLists = toDo.getFullCollection();
            fstream myfile;
            List currentList;
            string listTitle, activityTitle, activityDate, activityUrgent;
            bool bUrgent, firstList=true;
            int listIndex=-1;
            myfile.open ("ToDo.txt", ios::in);

            if(myfile.is_open()) {
                string line;

                while (getline(myfile, line)){
                    if (line[0] == '<') {
                        listTitle = line.substr(1, line.length()-2);

                        if (firstList) {
                            firstList = false;
                         }
                        else {
                            toDo.addList(currentList);
                            currentList.cleanList();
                        }

                        currentList.setTitolo(listTitle);
                    }
                    else {
                        activityTitle = line.substr(0, line.find(','));
                        line.erase(0, line.find(',') + 1);
                        activityDate = line.substr(0, line.find(','));
                        line.erase(0, line.find(',') + 1);
                        activityUrgent = line;

                        if (activityUrgent == "urgente")
                            bUrgent = true;
                        else
                            bUrgent = false;

                        Activity currentActivity(activityTitle,activityDate,bUrgent);
                        currentList.addActivity(currentActivity);

                    }

                }
                toDo.addList(currentList);
                myfile.close();
            }
        }
        azione =="";
    }

    return 0;
}

    void HandleList(CollectionLists& AllLists, int index) {
        List activeList(AllLists.getList(index));
        std::string azione, titolo, data, urg;
        int numAct;
        bool urgent;
        Activity a;

        cout << "Lista: " << activeList.getTitolo() << endl;  //su quale lista sto lavorando

        while (azione != "E") {
            std::cout << "[P] Elenco attivita' - [A] Aggiungi attivita' - [M] Modifica attivita' - [E] Ritorna al menu' principale"<< std::endl;
            std::cin >> azione;

            if (azione == "P") {
                activeList.listActivities();
            }
            else if (azione == "A") {
                std::cout << "Inserire titolo del nuovo promemoria" << std::endl;
                std::cin >> titolo;

                std::cout << "Inserire data per il promemoria" << std::endl;
                std::cin >> data;

                std::cout << "Il promemoria e' urgente? [Y] - [N]" << std::endl;
                std::cin >> urg;
                if (urg == "Y")
                    urgent = true;
                else
                    urgent = false;

                Activity b(titolo, data, urgent);
                activeList.addActivity(b);
                AllLists.editList(index, activeList);
                cout << "Nuova attivita' aggiunta: " << b.getDescription() << endl;
            }
            else if (azione == "M"){
                std::string set, newTitle, newDate, newUrgent;
                std::cout << "Inserisci numero dell'attivita' " <<std::endl;
                std::cin >> numAct;
                a = activeList.getActivity(numAct);   //lavoro sull'attività scelta dall'utente

                std::cout << a.getTitle() << std::endl;

                std::cout << "Cosa vuoi modificare? [T] Titolo - [D] Data - [U] Urgenza" << std::endl;
                std:: cin >> set;
                if (set == "T"){
                    std::cout << "Modifica titolo promemoria: " << std::endl;
                    std::cin >> newTitle;
                    a.setTitle(newTitle);
                } else if (set == "D"){
                    std::cout << "Imposta nuova data: " << std::endl;
                    std::cin >> newDate;
                    a.setDate(newDate);
                } else if (set == "U"){
                    if (a.isUrgent()) {
                        a.setUrgent(false);
                        std::cout << "Nuova urgenza: falso" << std::endl;
                    }
                    else {
                        a.setUrgent(true);
                        std::cout << "Nuova urgenza: vero " << std::endl;
                    }
                }

                activeList.editActivity(numAct, a.getTitle(), a.getDate(), a.isUrgent());
                AllLists.editList(index, activeList); //aggiorniamo la lista dentro la collezione principale così da non perdere gli aggiornamenti
                cout << "Attivita' modificata: " << a.getDescription() << endl;

            }
            azione =="";
        }

    }









    /* List DailyToDo("Daily");
    List WeeklyToDo("Weekly");
    List MonthlyToDo("Monthly");



    Activity a("Fare la spesa", "oggi", false);
    Activity b("Cambiare medico", "oggi", true);
    Activity c("Rivedere lezione di Analisi II", "settimana", true);
    Activity d("Comprare regalo per Carlo", "mese", false);
    Activity e("Pagare assicurazione macchina", "mese", true);
    Activity f("Controlla posta", "settimana", false);

    DailyToDo.addActivity(&a);
    DailyToDo.addActivity(&b);
    WeeklyToDo.addActivity(&c);
    MonthlyToDo.addActivity(&d);
    MonthlyToDo.addActivity(&e);
    WeeklyToDo.addActivity(&f);

    std::cout << "Oggi devo fare: " <<std:: endl;

    DailyToDo.activityList();


    std::cout << "Urgenti in giornata: " << std::endl;
    DailyToDo.urgentList();

    std::cout << "Questo mese devo fare: " << std::endl;
    MonthlyToDo.listActivities();
*/

