#include "interactionmodel.h"

InteractionModel::InteractionModel() : StorageHandler()
{

}

bool InteractionModel::create(Interaction interactionToAdd)
{
    bool success = false;
    QSqlQuery query;

    if(!isExist(interactionToAdd))
    {
        query.prepare("INSERT INTO \
                      interaction (type, title, date, participant, note, creation_date, modification_date) \
                      VALUES (:type, :title, :date, :participant, :note, :creation_date, :modification_date)");

        bindAll(interactionToAdd, query);

        if(query.exec())
            success = true;
        else
          showSQLError(query);
    }

   return success;
}

std::list<Interaction> InteractionModel::read()
{
    QSqlQuery query("SELECT * FROM interaction");
    std::list<Interaction> interactions;

    if(!query.exec())
      showSQLError(query);
    else{

        Interaction contactFound;
        if (query.last())
            do {
                contactFound = hydrate(contactFound, query);
                interactions.push_back(contactFound);
            } while (query.previous());
    }

    return interactions;
}

bool InteractionModel::update(Interaction oldInteraction, Interaction newInteraction)
{
    bool success = false;

    if(isExist(oldInteraction))
    {
        QSqlQuery query;
        query.prepare("UPDATE interaction                      \
                       SET type              =    :type,        \
                           title             =    :title,        \
                           date              =    :date,          \
                           participant       =    :participant,    \
                           note              =    :note,            \
                           creation_date    =    :creation_date,    \
                           modification_date =    :modification_date  \
                       WHERE id = :id");

        bindAll(newInteraction, query);

        if(query.exec())
            success = true;
        else
          showSQLError(query);
    }

    return success;
}

bool InteractionModel::isExist(Interaction interactionToFind)
{
    int nbRows = 0;
    QSqlQuery query;
    query.prepare("SELECT * FROM interaction WHERE id = :id");
    query.bindValue(":id", interactionToFind.getId());

    if(query.exec())
    {
        query.last();
        nbRows = query.at() + 1;
    }
    else
      showSQLError(query);

   return (nbRows > 0) ? true : false;
}

Interaction InteractionModel::hydrate(Interaction interactionToHydrate, QSqlQuery query)
{

    int id = query.value(0).toInt();
    std::string type = query.value(1).toString().toStdString();
    std::string title = query.value(2).toString().toStdString();
    std::string date = query.value(3).toString().toStdString();
    int participantId = query.value(4).toInt();
    std::string note = query.value(5).toString().toStdString();
    std::string creation = query.value(6).toString().toStdString();
    std::string modification = query.value(7).toString().toStdString();

    ContactModel contactModel;
    Contact participant = contactModel.findById(participantId);

    interactionToHydrate.setId(id);
    interactionToHydrate.setType(type);
    interactionToHydrate.setTitle(title);
    interactionToHydrate.setCreationDate(date);
    interactionToHydrate.setParticipants(participant);
    interactionToHydrate.setNote(note);
    interactionToHydrate.setCreationDate(date);
    interactionToHydrate.setModficationDate(modification);

    return interactionToHydrate;
}

void InteractionModel::bindAll(Interaction interactionToBind, QSqlQuery query)
{
    query.bindValue(":id", interactionToBind.getId());
    query.bindValue(":type", QString::fromStdString(interactionToBind.getType()));
    query.bindValue(":title", QString::fromStdString(interactionToBind.getTitle()));
    query.bindValue(":date", QString::fromStdString(interactionToBind.getDate()));
    query.bindValue(":participant", interactionToBind.getParticipant().getId());
    query.bindValue(":note", QString::fromStdString(interactionToBind.getNote()));
    query.bindValue(":creation_date", QString::fromStdString(interactionToBind.getCreationDate()));
    query.bindValue(":modification_date", QString::fromStdString(interactionToBind.getModificationDate()));
}

void InteractionModel::printAll()
{
    QSqlQuery query("SELECT * FROM interaction");

    if(!query.exec())
      showSQLError(query);
    else{

        while(query.next())
        {
            QString id = query.value(0).toString();
            QString type = query.value(1).toString();
            QString title = query.value(2).toString();
            QString date = query.value(3).toString();
            QString participant = query.value(4).toString();
            QString note = query.value(5).toString();
            QString creation = query.value(6).toString();
            QString modification = query.value(7).toString();

            std::cout << id.toStdString() << " | "
                      << type.toStdString() << " | "
                      << title.toStdString() << " | "
                      << date.toStdString() << " | "
                      << participant.toStdString() << " | "
                      << note.toStdString() << " | "
                      << creation.toStdString() << " | "
                      << modification.toStdString()
                      << "\n";
        }
    }

}

