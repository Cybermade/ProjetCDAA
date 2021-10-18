#include <string>
#include <iostream>
#include "contact.h"

Contact::Contact():T(),m_lastname("Unknown Name"),m_firstname("Unkown FirstName")
  ,m_company("Unknown Company"),m_mail("UnknownAtUnknownDotUnknown")
  ,m_phonenumber("Unknown Numberphone"),m_photo("Unknown Photo")
  ,m_creationdate(T.getDateddmmyyyy())
{

}
 Contact::Contact(std::string& name,std::string& firstname,std::string& company
         ,std::string& mail,std::string& phonenumber,
         std::string& photo)
    :T(),m_lastname(name),m_firstname(firstname),m_company(company),m_mail(mail)
    ,m_phonenumber(phonenumber),m_photo(photo),m_creationdate(T.getDateddmmyyyy())
{

}

void Contact::edit(std::string &name, std::string &firstname, std::string &company,
                   std::string &mail, std::string &phonenumber,
                   std::string &photo)
{
    this->setLastName(name);
    this->setFirstName(firstname);
    this->setCompany(company);
    this->setMail(mail);
    this->setPhoneNumber(phonenumber);
    this->setPhoto(photo);
    this->ajouterDateDeModif();
}





void Contact::ajouterDateDeModif()
{
    this->m_modificationdate = T.getDateddmmyyyy();
}

std::ostream& operator<<(std::ostream& stream, const Contact& contact)
{
    std::string firstname =  (!contact.getFirstName().empty()) ? contact.getFirstName() : "Undefined";
    std::string lastname =  (!contact.getLastName().empty()) ? contact.getLastName() : "Undefined";
    std::string mail =  (!contact.getMail().empty()) ? contact.getMail() : "Undefined";
    std::string phoneNumber =  (!contact.getPhoneNumber().empty()) ? contact.getPhoneNumber() : "Undefined";
    std::string company =  (!contact.getCompany().empty()) ? contact.getCompany() : "Undefined";
    std::string creationDate = contact.getCreationDate();
    std::string modificationDate = (!contact.getModificationDate().empty()) ? contact.getModificationDate() : "Undefined";

    return stream << "Firstname: " + firstname + "\n"
                     + "LastName: " + lastname + "\n"
                     + "Mail: " + mail + "\n"
                     + "Phone number: " + phoneNumber + "\n"
                     + "Compagny: " + company + "\n"
                     + "Creation date: " + creationDate + "\n"
                     + "Modification date: " + modificationDate + "\n"
                     + "--------------------------------------------" +"\n";

}

bool Contact::operator==(const Contact& b)
{
    return typeid (*this) == typeid (b)
           && this->getFirstName() == b.getFirstName()
           && this->getLastName() == b.getLastName();
}

std::string Contact::getLastName() const
{
  return m_lastname;
}
std::string Contact::getFirstName() const
{
  return m_firstname;
}
std::string Contact::getCompany() const
{
  return m_company;
}
std::string Contact::getMail() const
{
    return m_mail;
}
std::string Contact::getPhoneNumber() const
{
    return m_phonenumber;
}
std::string Contact::getPhoto() const
{
    return m_photo;
}
std::string Contact::getCreationDate() const
{
    return m_creationdate;
}
std::string Contact::getModificationDate() const
{
    return m_modificationdate;
}


void Contact::setLastName(std::string &name)
{
    m_lastname = name;
}
void Contact::setFirstName(std::string &firstname)
{
    m_firstname = firstname;
}
void Contact::setCompany(std::string &company)
{
    m_company = company;
}
void Contact::setMail(std::string &mail)
{
    m_mail = mail;
}
void Contact::setPhoneNumber(std::string &phonenumber)
{
    m_phonenumber = phonenumber;
}
void Contact::setPhoto(std::string &photo)
{
    m_photo = photo;
}
void Contact::setCreationdate(const std::string &newCreationdate)
{
    m_creationdate = newCreationdate;
}

void Contact::setModificationdate(const std::string &newModificationdate)
{
    m_modificationdate = newModificationdate;
}

Contact::~Contact()
{

}
