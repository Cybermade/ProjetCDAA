#pragma once
#include <string>

class Personne
{
private:
    std::string m_Nom;
    std::string m_Prenom;
    std::string m_Entreprise;
    std::string m_Mail;
    std::string m_Telephone;
    std::string m_Photo;
    std::string m_Datedecreation;
public:
    Personne();
    Personne(std::string& Nom,std::string& Prenom,std::string& Entreprise
             ,std::string& Mail,std::string& Telephone,
             std::string& Photo,std::string& Datedecreation);


    std::string getNom() const;
    std::string getPrenom() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    std::string getDatedecreation() const;



    void setNom(std::string& Nom);
    void setPrenom(std::string& Prenom);
    void setEntreprise(std::string& Entreprise);
    void setMail(std::string& Mail);
    void setTelephone(std::string& Telephone);
    void setPhoto(std::string& Photo);
    void setDatedecreation(std::string& Datedecreation);





};
