#pragma once
#include "storagehandler.h"
#include "logic/interaction.h"
#include "contactmodel.h"
#include <QVariant>
#include <QDebug>
#include<string>

class InteractionModel : public StorageHandler
{
private:
    Interaction hydrate(Interaction interactionToHydrate, QSqlQuery query);
    void bindAll(Interaction interactionToBind, QSqlQuery query);

public:
    InteractionModel();
    bool isExist(Interaction interactionToFind);
    bool create(Interaction interactionToAdd);
    std::list<Interaction> read();
    bool update(Interaction oldInteraction, Interaction newInteraction);
    bool deletePermanently(Interaction interactionToDelete);
    Interaction findByName(std::string nameToFind);
    void printAll();
};

