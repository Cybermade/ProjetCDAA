#pragma once
#include "currenttime.h"
#include <string>
#include <ctime>
#include <list>
#include <typeinfo>

class Contact
{
private:
    CurrentTime T;//Simple class de DateManagement
    std::string m_lastname;//nom
    std::string m_firstname;//prenom
    std::string m_company;//entreprise
    std::string m_mail;//mail
    std::string m_phonenumber;//telephone
    std::string m_photo;//photo
    std::string m_creationdate;//date de creation
    std::string m_modificationdate;//dernière date de modification

    //Update la date de modification
    void ajouterDateDeModif();

public:
    //Default Constructor
    Contact();

    //Destructor
    ~Contact();

    //Constructor
    Contact(std::string& name,std::string& firstname,std::string& company
             ,std::string& mail,std::string& phonenumber,
             std::string& photo);

    // Modifier toutes les infos (appelle tous les setters)
    void edit(std::string& name,std::string& firstname,std::string& company
         ,std::string& mail,std::string& phonenumber,
         std::string& photo);



    //GETTERS
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getCompany() const;
    std::string getMail() const;
    std::string getPhoneNumber() const;
    std::string getPhoto() const;
    std::string getCreationDate() const;
    std::string getModificationDate() const;


    //SETTERS
    void setLastName(std::string& name);
    void setFirstName(std::string& firstname);
    void setCompany(std::string& company);
    void setMail(std::string& mail);
    void setPhoneNumber(std::string& phonenumber);
    void setPhoto(std::string& photo);
    void setCreationdate(const std::string &newCreationdate);
    void setModificationdate(const std::string &newModificationdate);


    //Surchage de "<<" ce qui nous permet de print les infos d'un contact
    friend std::ostream& operator<<(std::ostream& stream, const Contact& contact);

    //Surchage de "==" ce qui nous permet de vérifier si 2 contacts sont égales(ici dans notre cas ils sont égales si ils ont le même
    //nom et le même prénom)
    bool operator==(const Contact& b);




};
