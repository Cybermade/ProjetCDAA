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
    std::string m_datelastdelete;//Date of last delete
    std::list<Contact> m_contactsmanagement;//Contacts management

public:
    //Default Constructor
    Contactsmanagement();
    //Destructor
    ~Contactsmanagement();


    void addContact(const Contact& c);

    void addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo);

    void editContact(unsigned int id,std::string& name,
                    std::string& firstname,std::string& company
                     ,std::string& mail,std::string& phonenumber,
                     std::string& photo);
    //show all contacts
    void showSheetAll();

    //id is the position of the contact in the list
    //Delete a single contact by id
    void deleteContact(unsigned int id);

    //delete everyone
    void deleteAll();


};
