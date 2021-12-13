#include "export.h"

Export::Export() : StorageHandler()
{

}

void Export::exportToJson()
{
    QJsonObject bdd;
    QDir dir;
    QString path = dir.currentPath() + "/data" + "/export.json";

    bdd["contacts"] = serializeContactsForJson();

    writeInJsonFile(bdd, path);

}


QJsonObject Export::serializeContactsForJson()
{
    QJsonObject contacts;

    QSqlQuery queryContact(" SELECT * FROM contact;");

    if(!queryContact.exec())
        showSQLError(queryContact);
    else {
        while (queryContact.next()) {
            QJsonObject contact;

            contact["lastname"] = queryContact.value(1).toString();
            contact["firstname"] = queryContact.value(2).toString();
            contact["compagny"] = queryContact.value(3).toString();
            contact["mail"] = queryContact.value(4).toString();
            contact["phone"] = queryContact.value(5).toString();
            contact["photo"] = queryContact.value(6).toString();
            contact["creation"] = queryContact.value(7).toString();
            contact["modification"] = queryContact.value(8).toString();

            contacts[queryContact.value(0).toString()] = contact;
        }
   }
   return contacts;
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
