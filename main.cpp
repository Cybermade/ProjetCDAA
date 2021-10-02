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
    std::string Nom = "Hamidou";
    std::string Prenom = "Nazim";
    std::string Entreprise = "Google";
    std::string Mail = "nazimatgmaildotcom";
    std::string Telephone = "21498024913";
    std::string Photo = "NOOO";
    std::string Nom2 = "Idk bro";
    

    Contactsmanagement C;

    Contact p ={Nom,Prenom,Entreprise,Mail,Telephone,Photo};
    Contact p1(Nom,Prenom,Entreprise,Mail,Telephone,Photo);
    Contact p3 = p1;

    C.addContact(p);
    C.addContact(p1);

    C.showSheetAll();
    C.editContact(4,Nom2,Photo,Mail,Entreprise,Telephone,Prenom);
    C.deleteAll();
    C.deleteAll();
    C.showSheetAll();




    return 0;

}
