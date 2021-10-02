#include "mainwindow.h"
#include <thread>
#include <chrono>
#include <QApplication>
#include <iostream>
#include "contact.h"
#include "contactsmanagement.h"
#include "currenttime.h"




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
    //C.editContact(1,Nom2,Photo,Mail,Entreprise,Telephone,Prenom);
    C.deleteContact(1);
    C.showSheetAll();
    C.deleteAll();
    C.deleteAll();
    C.showSheetAll();




    return 0;

}
