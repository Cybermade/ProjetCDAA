#pragma once
#include "currenttime.h"
#include <string>
#include <ctime>
#include <list>
class Contact
{
private:
    CurrentTime T;
    std::string m_name;
    std::string m_firstname;
    std::string m_company;
    std::string m_mail;
    std::string m_phonenumber;
    std::string m_photo;
    std::string m_creationdate;
    std::list <std::string>  m_historiquedemodif;

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

    // Edit All Informations (Call all setters)
    void edit(std::string& name,std::string& firstname,std::string& company
         ,std::string& mail,std::string& phonenumber,
         std::string& photo);

    void showContactSheet() const; //Print All Contact's infos (Call all getters)

    //GETTERS
    std::string getName() const;
    std::string getFirstName() const;
    std::string getCompany() const;
    std::string getMail() const;
    std::string getPhoneNumber() const;
    std::string getPhoto() const;
    std::string getCreationDate() const;


    //SETTERS
    void setName(std::string& name);
    void setFirstName(std::string& firstname);
    void setCompany(std::string& company);
    void setMail(std::string& mail);
    void setPhoneNumber(std::string& phonenumber);
    void setPhoto(std::string& photo);
    void setCreationDate(std::string& creationdate);



    friend std::ostream& operator<<(std::ostream& stream, const Contact& contact);

};
