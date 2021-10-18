#pragma once
#include <vector>
#include <list>
#include <string>
#include "contact.h"
#include "currenttime.h"

class Contactsmanagement
{
private:
    CurrentTime T;//Simple class de dateManagement
    std::string m_datelastdelete;//Date de la dernière suppresion
    std::list<Contact> m_contactsmanagement;//Contacts management

public:
    //Default Constructor
    Contactsmanagement();
    //Destructor
    ~Contactsmanagement();

    //On ajoute un contact directement d'une instance contact
    void addContact(const Contact& c);

    //On ajoute un contact via ses infos
    void addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo);

    //On modifie un contact via son id(son id est seulement sa place dans la list de contacts)
    void editContact(unsigned int id,std::string& name,
                    std::string& firstname,std::string& company
                     ,std::string& mail,std::string& phonenumber,
                     std::string& photo);
    //Print les infos de tous les contacts
    void showSheetAll()const;

    //id est la position du contact dans la liste
    //On supprime un contact via son id
    void deleteContactById(unsigned int id);

    //ON supprime tous les contacts qui sont égales au contact c
    void deleteContact(const Contact& c);


    //Surchage de l'operateur "+" pour rajouter un contact a un contactsmanagement (example Cm = Cm + c)
    Contactsmanagement operator+(const Contact& c);
    //Surchage de l'operateur "+=" pour rajouter un contact a un contactsmanagement (example Cm += c)
    Contactsmanagement operator+=(const Contact& c);
    //Surchage de l'operateur "-" pour supprimer un contact d'un contactsmanagement (example Cm = Cm - c)
    Contactsmanagement operator-(const Contact& c);
    //Surchage de l'operateur "-=" pour supprimer un contact d'un contactsmanagement (example Cm -= c)
    Contactsmanagement operator-=(const Contact& c);

    //delete everyone
    void deleteAll();


};
