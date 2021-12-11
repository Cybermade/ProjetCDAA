#include "contactmodel.h"

ContactModel::ContactModel() : StorageHandler()
{

}


bool ContactModel::create(Contact contactToAdd)
{
    bool success = false;
    QSqlQuery query;

    if(!isExist(contactToAdd))
    {
        query.prepare("INSERT INTO \
                      contact (lastname, firstname, compagny, mail, phone_number, photo, creation_date, modification_date) \
                      VALUES (:lastname, :firstname, :compagny, :mail, :phone_number, :photo, :creation_date, :modification_date)");

        bindAll(contactToAdd, query);

        if(query.exec())
            success = true;
        else
          showSQLError(query);
    }

   return success;
}


std::list<Contact> ContactModel::read()
{
    QSqlQuery query("SELECT * FROM contact");
    std::list<Contact> contacts;

    if(!query.exec())
      showSQLError(query);
    else{

        while(query.next())
        {
            Contact contactFound;
            contactFound = hydrate(contactFound, query);
            contacts.push_back(contactFound);
        }
    }

    return contacts;
}


bool ContactModel::update(Contact oldContact, Contact newContact)
{
    bool success = false;

    if(isExist(oldContact))
    {

        QSqlQuery query;
        query.prepare("UPDATE contact                         \
                       SET lastname          =    :lastname,   \
                           firstname         =    :firstname,   \
                           compagny          =    :compagny,     \
                           mail              =    :mail,          \
                           phone_number      =    :phone_number,   \
                           photo             =    :photo,           \
                           creation_date     =    :creation_date,    \
                           modification_date =    :modification_date  \
                       WHERE id = :id");

        bindAll(newContact, query);

        if(query.exec())
            success = true;
        else
          showSQLError(query);
    }

    return success;
}

bool ContactModel::deletePermanently(Contact contactToDelete)
{
    bool success = false;

    QSqlQuery query;
    query.prepare("DELETE FROM contact WHERE id = :id");
    query.bindValue(":id", contactToDelete.getId());

    if(query.exec())
        success = true;
    else
      showSQLError(query);

   return success;

}

Contact ContactModel::findByName(std::string nameToFind)
{
    Contact contactFound;
    QSqlQuery query;
    query.prepare("SELECT * FROM contact WHERE lastname = :lastname");
    query.bindValue(":lastname", QString::fromStdString(nameToFind));

    if(query.exec())
    {
        while (query.next())
        {
            contactFound = hydrate(contactFound, query);
        }
    }
    else
      showSQLError(query);


    return contactFound;
}

Contact ContactModel::findById(int id)
{
    Contact contactFound;
    QSqlQuery query;
    query.prepare("SELECT * FROM contact WHERE id = :id");
    query.bindValue(":id", id);

    if(query.exec())
    {
        while (query.next())
        {
            contactFound = hydrate(contactFound, query);
        }
    }
    else
      showSQLError(query);


    return contactFound;
}

bool ContactModel::isExist(Contact contactToFind)
{
    int nbRows = 0;
    QSqlQuery query;
    query.prepare("SELECT * FROM contact WHERE id = :id");
    query.bindValue(":id", contactToFind.getId());

    if(query.exec())
    {
        query.last();
        nbRows = query.at() + 1;
    }    
    else
      showSQLError(query);

   return (nbRows > 0) ? true : false;
}

Contact ContactModel::hydrate(Contact contactToHydrate, QSqlQuery query)
{
    int id = query.value(0).toInt();
    std::string lastname = query.value(1).toString().toStdString();
    std::string firstname = query.value(2).toString().toStdString();
    std::string compagny = query.value(3).toString().toStdString();
    std::string mail = query.value(4).toString().toStdString();
    std::string phone = query.value(5).toString().toStdString();
    std::string photo = query.value(6).toString().toStdString();
    std::string creation = query.value(7).toString().toStdString();
    std::string modification = query.value(8).toString().toStdString();


    contactToHydrate.setId(id);
    contactToHydrate.setFirstName(firstname);
    contactToHydrate.setLastName(lastname);
    contactToHydrate.setCompany(compagny);
    contactToHydrate.setMail(mail);
    contactToHydrate.setPhoneNumber(phone);
    contactToHydrate.setPhoto(photo);
    contactToHydrate.setCreationdate(creation);
    contactToHydrate.setModificationdate(modification);

    return contactToHydrate;
}

void ContactModel::bindAll(Contact contactToBind, QSqlQuery query)
{
    query.bindValue(":id", contactToBind.getId());
    query.bindValue(":lastname", QString::fromStdString(contactToBind.getLastName()));
    query.bindValue(":firstname", QString::fromStdString(contactToBind.getFirstName()));
    query.bindValue(":compagny", QString::fromStdString(contactToBind.getCompany()));
    query.bindValue(":mail", QString::fromStdString(contactToBind.getMail()));
    query.bindValue(":phone_number", QString::fromStdString(contactToBind.getPhoneNumber()));
    query.bindValue(":photo", QString::fromStdString(contactToBind.getPhoto()));
    query.bindValue(":creation_date", QString::fromStdString(contactToBind.getCreationDate()));
    query.bindValue(":modification_date", QString::fromStdString(contactToBind.getModificationDate()));
}

void ContactModel::printAll()
{
    QSqlQuery query("SELECT * FROM contact");

    if(!query.exec())
      showSQLError(query);
    else{

        Contact contact;

        showBDDstatus();
        while(query.next())
        {
            QString id = query.value(0).toString();
            QString lastname = query.value(1).toString();
            QString firstname = query.value(2).toString();
            QString compagny = query.value(3).toString();
            QString mail = query.value(4).toString();
            QString phone = query.value(5).toString();
            QString photo = query.value(6).toString();
            QString creation = query.value(7).toString();
            QString modification = query.value(8).toString();
            std::cout << id.toStdString() << " | "
                      << lastname.toStdString() << " | "
                      << firstname.toStdString() << " | "
                      << compagny.toStdString() << " | "
                      << mail.toStdString() << " | "
                      << phone.toStdString() << " | "
                      << photo.toStdString() << " | "
                      << creation.toStdString() << " | "
                      << modification.toStdString()
                      << "\n";
        }
    }

}
