#pragma once
#include <vector>
#include <list>
#include <string>
#include "contact.h"
#include "currenttime.h"

class Contactsmanagement
{
private:
    CurrentTime T;
    std::string m_Datesuppresion;
    std::list<Contact> m_Gestionpersonnes;

public:
    Contactsmanagement();
    ~Contactsmanagement();
    void addContact(const Contact& c);

    void addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo);

    void editContact(unsigned int id,std::string& name,
                    std::string& firstname,std::string& company
                     ,std::string& mail,std::string& phonenumber,
                     std::string& photo);

    void showSheetAll();

    //id is the position of the contact in the list
    void deleteContact(unsigned int id);
    void deleteAll();


};
