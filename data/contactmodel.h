#pragma once
#include <string>
#include "logic/contact.h"
#include "storagehandler.h"
#include <QVariant>
#include <QDebug>
#include<string>

/** TODO : ajouter un soft delete */
class ContactModel : public StorageHandler
{

public:
    ContactModel();
    Contact hydrate(Contact contactToHydrate, QSqlQuery query);
    void bindAll(Contact contactToBind, QSqlQuery query);
    void bindNameAndFirstName(Contact contactToBiend, QSqlQuery query);
    bool create(Contact ContactToAdd);
    std::list<Contact> read();
    bool update(Contact oldContact, Contact newContact);
    bool deletePermanently(Contact ContactToDelete);
    void printAll();
    bool isExist(Contact ContactToFind);
    Contact findByName(std::string nameToFind);

};

