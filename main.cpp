#include <iostream>
#include "Activity.h"
#include "List.h"
#include "CollectionLists.h"
#include <fstream>
#include <vector>
void HandleList(CollectionLists AllLists, int index);
using namespace std;

int main() {
    std::string titolo, azione;
    CollectionLists toDo;

    std::cout << "Inserire titolo della prima lista"<< std::endl;
    std::cin >> titolo;
    toDo.addList(titolo);

    while (azione != "Q") {
        std::cout << "[L] Elenco liste - [A] Aggiungi lista - [M] Modifica lista - [S] Salva su file - [Q] Esci"<< std::endl;
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

                    cout << "countActivities = " << loopList.countActivities();

                    for (int j = 0; j < loopList.countActivities(); j++) {
                        myfile << " " << loopList.getActivity(j).getDescription() << std::endl;
                    }
                };

                myfile.close();
            }
        }
        azione =="";
    }

    return 0;
}

    void HandleList(CollectionLists AllLists, int index) {
        List ActiveList(AllLists.getList(index));
        std::string azione, titolo, data, urg;
        int numAct;
        bool urgent;
        Activity a;

        while (azione != "E") {
            std::cout << "[P] Elenco attivita' - [A] Aggiungi attivita' - [M] Modifica attivita' - [E] Ritorna al menu' principale"<< std::endl;
            std::cin >> azione;

            if (azione == "P") {
                ActiveList.listActivities();
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
                ActiveList.addActivity(b);

            }
            else if (azione == "M"){
                std::string set, newTitle, newDate, newUrgent;
                std::cout << "Inserisci numero dell'attivita' " <<std::endl;
                std::cin >> numAct;
                a = ActiveList.getActivity(numAct);   //lavoro sull'attività scelta dall'utente

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

                ActiveList.addActivity(a);
                ActiveList.removeActivity(numAct);
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

