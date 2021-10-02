#include <iostream>
#include "contactsmanagement.h"

Contactsmanagement::Contactsmanagement():T(),m_datelastdelete("No Delete Yet")
{
    //void
}
void Contactsmanagement::addContact(const Contact &c)
{
    this->m_contactsmanagement.push_front(c);
}

void Contactsmanagement::addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo)
{
    this->m_contactsmanagement.push_front(Contact(name,firstname,company,mail,phonenumber,photo));

}

void Contactsmanagement::editContact(unsigned int id, std::string &name, std::string &firstname, std::string &company, std::string &mail, std::string &phonenumber, std::string &photo)
{   try {
        if ( m_contactsmanagement.size() > id )
        {
            std::list<Contact>::iterator itr = m_contactsmanagement.begin();
            std::advance(itr,id);
            itr->edit(name,firstname,company,mail,phonenumber,photo);
        }
        else
        {
            throw id;
        }
    }
    catch (unsigned int id) {
        std::cout << "The Size Of The List Of Contacts Should Be Greater Than The Id"<<std::endl;
    }

}

void Contactsmanagement::showSheetAll()
{   int size = m_contactsmanagement.size();
    try {
        if(size > 0)
        {
            for(auto const &c :m_contactsmanagement)
            {
                c.showContactSheet();
            }
            std::cout << "Last Delete : "<<m_datelastdelete<< std::endl;
        }
        else
        {
            throw size;
        }
        }
    catch (int size) {
        std::cout << "No Contact(s) To Show"<<std::endl;

    }

}

void Contactsmanagement::deleteContact(unsigned int id)
{   try {
        if ( m_contactsmanagement.size() > id )
        {
            std::list<Contact>::iterator itr = m_contactsmanagement.begin();
            std::advance(itr,id);
            m_contactsmanagement.erase(itr);
            m_datelastdelete = T.getDateddmmyyyyhhmm();
        }
        else{
            throw id;
        }
    }
    catch(unsigned int id)
    {
        std::cout << "The Size Of The List Of Contacts Should Be Greater Than The Id"<<std::endl;
    }


}

void Contactsmanagement::deleteAll()
{   int size = m_contactsmanagement.size();
    try {
        if(size > 0)
        {
            m_contactsmanagement.clear();
            m_datelastdelete = T.getDateddmmyyyyhhmm();
        }
        else
        {
            throw size;
        }
    }
    catch(int size)
    {
        std::cout << "You Cannot Delete An Already Empty List"<< std::endl;
    }

}

Contactsmanagement::~Contactsmanagement()
{
    m_contactsmanagement.clear();
}

