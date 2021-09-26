#pragma once
#include <vector>
#include <list>
#include <string>
#include "Personne.h"
class GestionPersonnes
{
private:
    std::string m_Datesuppresion;
    std::list<Personne> m_Gestionpersonnes;

public:

    void AddPersonne(const Personne& p);
    void AddPersonne(std::string Nom,std::string Prenom,
                    std::string Entreprise,std::string Mail,
                    std::string Telephone,std::string Photo,
                     std::string Datedecreation);

    void AfficherPersonnes();




};
