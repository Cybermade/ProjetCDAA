#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "Personne.h"
#include "GestionPersonnes.h"



void affichePersonne(const Personne& P)
{
    std::cout <<P.getNom()<<std::endl
    <<P.getPrenom()<<std::endl
    <<P.getEntreprise()<<std::endl
    <<P.getMail()<<std::endl
    <<P.getTelephone()<<std::endl<<P.getPhoto()<<std::endl
      <<P.getDatedecreation()<<std::endl;

}

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
    std::string Datedecreation = "01/01/1970";

    Personne p;
    Personne p1(Nom,Prenom,Entreprise,Mail,Telephone,Photo,Datedecreation);

    GestionPersonnes GP;
    GP.AddPersonne(p);
    GP.AddPersonne(p1);
    GP.AfficherPersonnes();

    return 0;

}
