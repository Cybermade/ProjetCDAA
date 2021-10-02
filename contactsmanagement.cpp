#include <iostream>
#include "contactsmanagement.h"

Contactsmanagement::Contactsmanagement():T(),m_Datesuppresion("No Delete Yet")
{
    //void
}
void Contactsmanagement::addContact(const Contact &c)
{
    this->m_Gestionpersonnes.push_front(c);
}

void Contactsmanagement::addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo)
{
    this->m_Gestionpersonnes.push_front(Contact(name,firstname,company,mail,phonenumber,photo));

}

void Contactsmanagement::editContact(unsigned int id, std::string &name, std::string &firstname, std::string &company, std::string &mail, std::string &phonenumber, std::string &photo)
{   try {
        if ( m_Gestionpersonnes.size() > id )
        {
            std::list<Contact>::iterator itr = m_Gestionpersonnes.begin();
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
{   int size = m_Gestionpersonnes.size();
    try {
        if(size > 0)
        {
            for(auto const &c :m_Gestionpersonnes)
            {
                c.showContactSheet();
            }
            std::cout << "Last Delete : "<<m_Datesuppresion<< std::endl;
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
        if ( m_Gestionpersonnes.size() > id )
        {
            std::list<Contact>::iterator itr = m_Gestionpersonnes.begin();
            std::advance(itr,id);
            m_Gestionpersonnes.erase(itr);
            m_Datesuppresion = T.getDateddmmyyyyhhmm();
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
{   int size = m_Gestionpersonnes.size();
    try {
        if(size > 0)
        {
            m_Gestionpersonnes.clear();
            m_Datesuppresion = T.getDateddmmyyyyhhmm();
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
    m_Gestionpersonnes.clear();
}

