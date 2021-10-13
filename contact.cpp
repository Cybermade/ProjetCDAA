#include <string>
#include <iostream>
#include "contact.h"

Contact::Contact():T(),m_name("Unknown Name"),m_firstname("Unkown FirstName")
  ,m_company("Unknown Company"),m_mail("UnknownAtUnknownDotUnknown")
  ,m_phonenumber("Unknown Numberphone"),m_photo("Unknown Photo")
  ,m_creationdate("Unknown CreationDate")
{

}
 Contact::Contact(std::string& name,std::string& firstname,std::string& company
         ,std::string& mail,std::string& phonenumber,
         std::string& photo)
    :T(),m_name(name),m_firstname(firstname),m_company(company),m_mail(mail)
    ,m_phonenumber(phonenumber),m_photo(photo),m_creationdate(T.getDateddmmyyyy())
{

}

void Contact::edit(std::string &name, std::string &firstname, std::string &company,
                   std::string &mail, std::string &phonenumber,
                   std::string &photo)
{
    this->setName(name);
    this->setFirstName(firstname);
    this->setCompany(company);
    this->setMail(mail);
    this->setPhoneNumber(phonenumber);
    this->setPhoto(photo);
    //this->setCreationDate(creationdate);
    this->ajouterDateDeModif();
}

void Contact::showContactSheet() const
{
    std::cout << "Name : "<<this->getName() <<" First Name : " << this->getFirstName()
              <<" Company : "<<this->getCompany()<<" Mail : "<<this->getMail()
             <<" Phone Number : "<<this->getPhoneNumber()<<" Photo : "<<this->getPhoto()
               << " Creation Date : "<<this->getCreationDate()<<std::endl;
    if(m_historiquedemodif.size()>0)
    {std::cout<<"Modifications from the last one :"<<std::endl;
    for(auto const& modif:m_historiquedemodif)
    {
        std::cout<<modif<<"\n";
    }
    }

}

void Contact::ajouterDateDeModif()
{
    this->m_historiquedemodif.push_front(T.getDateddmmyyyyhhmmss());
}

std::ostream& operator<<(std::ostream& stream, const Contact& contact)
{
    std::string firstname =  (!contact.getFirstName().empty()) ? contact.getFirstName() : "Undefined";
    std::string lastname =  (!contact.getName().empty()) ? contact.getName() : "Undefined";
    std::string mail =  (!contact.getMail().empty()) ? contact.getMail() : "Undefined";
    std::string phoneNumber =  (!contact.getPhoneNumber().empty()) ? contact.getPhoneNumber() : "Undefined";
    std::string compagny =  (!contact.getCompany().empty()) ? contact.getCompany() : "Undefined";
    std::string creationDate = contact.getCreationDate();

    return stream << "Firstname: " + firstname + "\n"
                     + "LastName: " + lastname + "\n"
                     + "Mail: " + mail + "\n"
                     + "Phone number: " + phoneNumber + "\n"
                     + "Compagny: " + compagny + "\n"
                     + "Creation date: " + creationDate + "\n";

}

bool operator==(const Contact& a, const Contact& b)
{
    return typeid (a) == typeid (b)
           && a.getFirstName() == b.getFirstName()
           && a.getName() == b.getName();
}

std::string Contact::getName() const
{
  return m_name;
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

void Contact::setName(std::string &name)
{
    m_name = name;
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
void Contact::setCreationDate(std::string &creationdate)
{
    m_creationdate = creationdate;
}
Contact::~Contact()
{
    m_historiquedemodif.clear();
}
