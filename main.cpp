#include "gui/mainwindow.h"
#include <thread>
#include <chrono>
#include <QApplication>
#include <iostream>
#include <iomanip>
#include "logic/contact.h"
#include "logic/contactsmanagement.h"
#include "logic/currenttime.h"
#include "logic/interaction.h"
#include "logic/interactionHandler.h"
#include "logic/todo.h"



//test
int main(int argc, char *argv[])
{
/*    CurrentTime time = CurrentTime();

    //Création d'un contact
    std::string nom1 = "Dupont";
    std::string prenom1 = "Marie";
    std::string entreprise1 = "Facebook";
    std::string mail1 = "example@gmail.com";
    std::string tel1 = "568-485-522";
    std::string photo1 = "/path/to/photo/marie";
    Contact p1 = Contact(nom1, prenom1, entreprise1, mail1, tel1, photo1);

    //Création d'un contact
    std::string nom2 = "Edouard";
    std::string prenom2 = "Albert";
    std::string entreprise2 = "google";
    std::string mail2 = "example@gmail.com";
    std::string tel2 = "651-568-128";
    std::string photo2 = "/path/to/photo/albert";
    Contact p2 = Contact(nom2, prenom2, entreprise2, mail2, tel2, photo2);

    //creation d'une interaction
    std::string type1 = "Call";
    std::string titre1 = "Visio avec Roubashof";
    std::string note1 = "La porte de la cellule claqua en se refermant sur Roubachof";
    Interaction i1 = Interaction(type1, titre1, p1, note1);

    //creation d'une interaction
    std::string type2 = "Meeting";
    std::string titre2 = "Réunion avec Jean-Paul Sartre";
    std::string note2 = "L'existentialisme est un humanisme";
    Interaction i2 = Interaction(type2, titre2, p2, note2);

    //création d'un todo
    std::string contenu1 = "vérifier si Albert Camus et J-P Sartre sont proches";
    ToDo todo1 = ToDo(contenu1);

    //création d'un todo
    std::string contenu2 = "demander un autographe par mail avant";
    std::string date1 = "22/10/2021";
    ToDo todo2 = ToDo(contenu2, date1);

    //gestionnaire de contact
    Contactsmanagement contacts = Contactsmanagement();

    //gestionnaire d'interaction
    InteractionHandler interactions = InteractionHandler();

    std::cout << "Affichage d'un contact \n";
    std::cout <<"---------- \n";

    std::cout << p1;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    //edition d'un contact
    std::cout << "Affichage d'un contact modifié \n";
    std::cout <<"---------- \n";

    std::string nom1Correct = "Dupond";
    p1.edit(nom1Correct, prenom1, entreprise1, mail1, tel1, photo1);
    std::cout << p1;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage de la liste de contact à sa création \n";
    std::cout <<"---------- \n";

    contacts.showSheetAll();

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage de la liste de contact après deux ajout \n";
    std::cout <<"---------- \n";

    contacts.addContact(p1);
    contacts += p2;
    contacts.showSheetAll();

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage de la liste de contact après la suppression d'un contact \n";
    std::cout <<"---------- \n";

    contacts.deleteContact(p1);
    contacts.showSheetAll();

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage d'une interaction après sa création \n";
    std::cout <<"---------- \n";

    std::cout << i1;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage d'une interaction après avoir ajouté des todo \n";
    std::cout <<"---------- \n";

    i2.addToDo(todo1);
    i2.addToDo(todo2);
    std::cout << i1;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage d'une interaction après modification \n";
    std::cout <<"---------- \n";

    std::string titrecorrect = "Réunion avec Jean-Paul Sartre";
    i2.edit(type2, titrecorrect, p2, note2, time.getDateddmmyyyy());
    std::cout << i2;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage de la liste d'interaction à sa création \n";
    std::cout <<"---------- \n";

    interactions.showAllInteractions();

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage de la liste d'interactions après deux ajout \n";
    std::cout <<"---------- \n";

    interactions.addAnInteraction(i1);
    interactions.addAnInteraction(i2);
    interactions.InteractionById(0).edit(type2,titre1,p1,note1,"time.getDateddmmyyyy()");
    interactions.showAllInteractions();

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage des interactions par date \n";
    std::cout <<"---------- \n";

    std::string today = time.getDateddmmyyyy();
    for(Interaction &i : interactions.getAllInteractionsByDate(today))
        std::cout << i;

    std::cout << "----------  END\n";
    std::cout <<"\n";

    std::cout << "Affichage des interactions par participant \n";
    std::cout <<"---------- \n";

    for(Interaction &i : interactions.getAllInteractionsByParticipant(p2))
        std::cout << i;

    std::cout << "----------  END\n";
    std::cout <<"\n";


    std::cout << "Affichage de la liste d'interactions après la suppression d'une interaction \n";
    std::cout <<"---------- \n";

    //interactions.deleteAnInteraction(i2);
    interactions.showAllInteractions();

    std::cout << "----------  END\n";
    std::cout <<"\n";*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();



}
