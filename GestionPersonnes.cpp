#include <iostream>
#include "GestionPersonnes.h"

void GestionPersonnes::AddPersonne(const Personne &p)
{
    m_Gestionpersonnes.push_back(p);
}
void GestionPersonnes::AddPersonne(std::string Nom, std::string Prenom, std::string Entreprise,
                                   std::string Mail, std::string Telephone,
                                   std::string Photo,
                                   std::string Datedecreation)
{
    Personne p(Nom,Prenom,Entreprise,Mail,Telephone,Photo,Datedecreation);
    m_Gestionpersonnes.push_back(p);
}
void GestionPersonnes::AfficherPersonnes()
{
    for(auto& P:m_Gestionpersonnes)
    {
        std::cout<<P.getNom()<<" "<<P.getPrenom()<<" "<<P.getEntreprise()<<" "
           <<P.getMail()<<" "<<P.getTelephone()<<" "<<P.getPhoto()<<" "<<
             P.getDatedecreation()<<std::endl;
    }
}

