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
/*
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

    std::cout << "\n// surchage opérateur << pour todo //" << std::endl;
    std::string ToDoContent = "Appeler M. X pour l'affaire Y";
    ToDo rdv = ToDo(ToDoContent, date);
    std::cout << rdv;
    std::cout << "\n";
    */

    return 0;
}
