#include "mainwindow.h"
#include <thread>
#include <chrono>
#include <QApplication>
#include <iostream>
#include <iomanip>
#include "contact.h"
#include "contactsmanagement.h"
#include "currenttime.h"
#include "interaction.h"
#include "interactionHandler.h"
#include "todo.h"




int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
    std::string Nom = "Dupont";
    std::string Prenom = "Marie";
    std::string Entreprise = "Google";
    std::string Mail = "Marieatgmaildotcom";
    std::string Telephone = "21498024913";
    std::string Photo = "photo1";
    std::string Nom2 = "Durant";
    std::string Prenom2 = "Maurice";
    std::string Entreprise2 = "Facebook";
    std::string Mail2 = "Mauriceatgmaildotcom";
    std::string Telephone2 = "113241523312";
    std::string Photo2 = "photo2";

    

    Contactsmanagement C;

    Contact p ={Nom,Prenom,Entreprise,Mail,Telephone,Photo};
    Contact p1(Nom2,Prenom2,Entreprise2,Mail2,Telephone2,Photo2);


    C.addContact(p);
    C.addContact(p1);

    C.showSheetAll();
    C.editContact(1,Nom2,Photo,Mail,Entreprise,Telephone,Prenom);
    C.deleteContact(1);
    C.showSheetAll();
    C.deleteAll();
    C.deleteAll();
    C.showSheetAll();

    std::cout << "\n// surchage opérateur << pour contact //" << std::endl;
    std::cout << p;

    std::cout << "\n// remplissage et surchage opérateur << pour interaction //" << std::endl;
    Interaction meet = Interaction();
    std::cout << meet;

    std::string type = "Meeting";
    std::string title = "Une superbe réunion";
    std::string note = "ceci est une note";
    Interaction meet2 = Interaction(type, title, p, note);
    std::cout << meet2;


    std::cout << "\n// Affichage des interactions du type \"Meeting\" //" << std::endl;
    std::string typeInteractionToShow = "Meeting";
    InteractionHandler interactions = InteractionHandler();
    interactions.addAnInteraction(meet);
    interactions.addAnInteraction(meet2);
    for(const Interaction& interaction : interactions.getAllInteractionsByType(typeInteractionToShow))
        std::cout << interaction;

    std::cout << "\n// Affichage des interactions de Dupont Marie //" << std::endl;
    for(const Interaction& interaction : interactions.getAllInteractionsByParticipant(p))
        std::cout << interaction;

    std::cout << "\n// Affichage des interactions du 17/10/2021 //" << std::endl;
    std::string date = "17/10/2021";
    for(const Interaction& interaction : interactions.getAllInteractionsByDate(date))
        std::cout << interaction;

    std::cout << "\n// Modification d'une interaction //" << std::endl;
    std::string typeEdit = "code review";
    std::string titleEdit = "Une superbe réunion";
    std::string noteEdit = "ceci est une note";
    std::string dateEdit = "20/08/2022";
    meet2.edit(typeEdit, titleEdit, p1, noteEdit, dateEdit);
    std::cout << meet2;

    /*
    std::cout << "\n// surchage opérateur << pour todo //" << std::endl;
    std::string ToDoContent = "Appeler M. X pour l'affaire Y";
    ToDo rdv = ToDo(ToDoContent, date);
    std::cout << rdv;
    std::cout << "\n";
    */

    return 0;

}
