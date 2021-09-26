#include <string>
#include "Personne.h"
Personne::Personne():m_Nom("Unknown Surname"),m_Prenom("Unkown Name")
  ,m_Entreprise("Unknown Entreprise"),m_Mail("UnknownAtUnknownDotUnknown")
  ,m_Telephone("Unknown Numberphone"),m_Photo("Unknown Photo")
  ,m_Datedecreation("Unknown CreationDate")
{

}
Personne::Personne(std::string& Nom,std::string& Prenom,std::string& Entreprise
                   ,std::string& Mail,std::string& Telephone,
                   std::string& Photo,std::string& Datedecreation)
    :m_Nom(Nom),m_Prenom(Prenom),m_Entreprise(Entreprise),m_Mail(Mail)
    ,m_Telephone(Telephone),m_Photo(Photo),m_Datedecreation(Datedecreation)
{

}

std::string Personne::getNom() const
{
  return m_Nom;
}
std::string Personne::getPrenom() const
{
  return m_Prenom;
}
std::string Personne::getEntreprise() const
{
  return m_Entreprise;
}
std::string Personne::getMail() const
{
    return m_Mail;
}
std::string Personne::getTelephone() const
{
    return m_Telephone;
}
std::string Personne::getPhoto() const
{
    return m_Photo;
}
std::string Personne::getDatedecreation() const
{
    return m_Datedecreation;
}

void Personne::setNom(std::string &Nom)
{
    m_Nom = Nom;
}
void Personne::setPrenom(std::string &Prenom)
{
    m_Prenom = Prenom;
}
void Personne::setEntreprise(std::string &Entreprise)
{
    m_Entreprise = Entreprise;
}
void Personne::setMail(std::string &Mail)
{
    m_Mail = Mail;
}
void Personne::setTelephone(std::string &Telephone)
{
    m_Telephone = Telephone;
}
void Personne::setPhoto(std::string &Photo)
{
    m_Photo = Photo;
}
void Personne::setDatedecreation(std::string &Datedecreation)
{
    m_Datedecreation = Datedecreation;
}
