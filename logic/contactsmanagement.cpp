#include <iostream>
#include "contactsmanagement.h"


Contactsmanagement::Contactsmanagement():T(),m_datelastdelete("No Delete Yet")
{
    fetchBDD();
}
void Contactsmanagement::addContact(const Contact &c)
{
    this->m_contactsmanagement.push_back(c);
}

void Contactsmanagement::addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo)
{
    this->m_contactsmanagement.push_back(Contact(name,firstname,company,mail,phonenumber,photo));
    this->linkWithBDD.create(Contact(name,firstname,company,mail,phonenumber,photo));
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

void Contactsmanagement::showSheetAll()const
{   int size = m_contactsmanagement.size();
    try {
        if(size > 0)
        {
            for(auto const &c :m_contactsmanagement)
            {
                std::cout << c;
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



void Contactsmanagement::deleteContactById(unsigned int id)
{   try {
        if ( m_contactsmanagement.size() > id )
        {
            std::list<Contact>::iterator itr = m_contactsmanagement.begin();
            std::advance(itr,id);
            m_contactsmanagement.erase(itr);
            m_datelastdelete = T.getDateddmmyyyy();
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
void Contactsmanagement::deleteContact(const Contact &c)
{   int size = (int)m_contactsmanagement.size();
    try {
            if ( m_contactsmanagement.size() != 0 )
            {
                this->m_contactsmanagement.remove(c);
                if(size != (int)m_contactsmanagement.size())
                    m_datelastdelete = T.getDateddmmyyyy();
            }
            else{
                throw size;
            }
        }
        catch(unsigned int size)
        {
            std::cout << "The Size Of The List Of Contacts Shouldn't Be Empty Or you Gave an Unknown Contact"<<std::endl;
        }
}
void Contactsmanagement::deleteAll()
{   int size = m_contactsmanagement.size();
    try {
        if(size > 0)
        {
            m_contactsmanagement.clear();
            m_datelastdelete = T.getDateddmmyyyy();
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
Contactsmanagement Contactsmanagement::operator+(const Contact &c)
{
    this->addContact(c);
    return *this;
}
Contactsmanagement Contactsmanagement::operator+=(const Contact &c)
{
    this->addContact(c);
    return *this;
}
Contactsmanagement Contactsmanagement::operator-(const Contact &c)
{
    this->deleteContact(c);
    return *this;
}
Contactsmanagement Contactsmanagement::operator-=(const Contact &c)
{
    this->deleteContact(c);
    return *this;
}

Contactsmanagement::~Contactsmanagement()
{
    m_contactsmanagement.clear();
}
Contact Contactsmanagement::ContactById(unsigned int id)
{
    try {
            if ( m_contactsmanagement.size() > id )
            {
                std::list<Contact>::iterator itr = m_contactsmanagement.begin();
                std::advance(itr,id);
                return(*itr);
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

std::list<Contact> Contactsmanagement::getContactsList()
{
    return m_contactsmanagement;
}

void Contactsmanagement::fetchBDD()
{
    std::list<Contact> contactFromBDD = this->linkWithBDD.read();
    this->m_contactsmanagement.insert(this->m_contactsmanagement.end(), contactFromBDD.begin(), contactFromBDD.end());
}
