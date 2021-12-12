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

private:
    Contact hydrate(Contact contactToHydrate, QSqlQuery query);
    void bindAll(Contact contactToBind, QSqlQuery query);

public:

    ContactModel();
    bool isExist(Contact ContactToFind);
    bool create(Contact ContactToAdd);
    std::list<Contact> read();
    bool update(Contact oldContact, Contact newContact);
    bool deletePermanently(Contact ContactToDelete);
    Contact findByName(std::string nameToFind);
    Contact findById(int id);
    void printAll();

};

