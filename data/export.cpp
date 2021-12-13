#include "export.h"

Export::Export() : StorageHandler()
{

}

void Export::exportToJson()
{
    QJsonObject bdd;
    QDir dir;
    QString path = dir.currentPath() + "/data" + "/export.json";

    bdd["contacts"] = serializeContactsJson();
    bdd["interactions"] = serializeInteractionsJson();
    bdd["todos"] = serializeToDoJson();

    writeInJsonFile(bdd, path);

}

QJsonObject Export::serializeContactsJson()
{
    QJsonObject contacts;

    QSqlQuery queryContacts("SELECT * FROM contact");

    if(!queryContacts.exec())
        showSQLError(queryContacts);
    else {
        while (queryContacts.next()) {
            QJsonObject contact;

            contact["lastname"] = queryContacts.value(1).toString();
            contact["firstname"] = queryContacts.value(2).toString();
            contact["compagny"] = queryContacts.value(3).toString();
            contact["mail"] = queryContacts.value(4).toString();
            contact["phone"] = queryContacts.value(5).toString();
            contact["photo"] = queryContacts.value(6).toString();
            contact["creation"] = queryContacts.value(7).toString();
            contact["modification"] = queryContacts.value(8).toString();

            contacts[queryContacts.value(0).toString()] = contact;
        }
   }

   return contacts;
}

QJsonObject Export::serializeInteractionsJson()
{
    QJsonObject interactions;

    QSqlQuery queryInteractions("SELECT * FROM interaction");

    if(!queryInteractions.exec())
        showSQLError(queryInteractions);
    else{
        while(queryInteractions.next())
        {
           QJsonObject interaction;

           interaction["type"] = queryInteractions.value(1).toString();
           interaction["title"] = queryInteractions.value(2).toString();
           interaction["date"] = queryInteractions.value(3).toString();
           interaction["participant"] = queryInteractions.value(4).toString();
           interaction["note"] = queryInteractions.value(5).toString();
           interaction["modification date"] = queryInteractions.value(6).toString();
           interaction["creation date"] = queryInteractions.value(7).toString();

           interactions[queryInteractions.value(0).toString()] = interaction;
        }
    }

   return interactions;
}

QJsonObject Export::serializeToDoJson()
{
    QJsonObject todos;

    QSqlQuery queryToDos("SELECT * FROM todo");

    if(!queryToDos.exec())
        showSQLError(queryToDos);
    else
    {
        while(queryToDos.next())
        {
            QJsonObject todo;

            todo["contenu"] = queryToDos.value(1).toString();
            todo["date"] = queryToDos.value(2).toString();
            todo["interaction"] = queryToDos.value(3).toString();

            todos[queryToDos.value(0).toString()] = todo;
        }
    }

    return todos;
}

void Export::writeInJsonFile(QJsonObject jsonObjectToWrite, QString fileToWrite)
{
    QFile file;
    file.setFileName(fileToWrite);

    QByteArray byteArray;
    byteArray = QJsonDocument(jsonObjectToWrite).toJson();

    if(!file.open(QIODevice::WriteOnly))
        std::cout << "no write access for json file";
    else{
        file.write(byteArray);
        file.close();
    }
}
