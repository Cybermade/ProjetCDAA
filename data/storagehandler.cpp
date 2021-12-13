#include "storagehandler.h"

StorageHandler::StorageHandler()
{
    configureBDDConnection();
    setBDDStatus(isBDDConnection());
}

void StorageHandler::configureBDDConnection()
{
    QDir path;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path.currentPath() + "/data/data.bd");
}


bool StorageHandler::isBDDConnection()
{
    return database.open();
}

void StorageHandler::setBDDStatus(const bool& status)
{
    BDDStatus = status;
}

void StorageHandler::showBDDstatus()
{
    std::string debugInfo = "BDD connection : not exist \n";

    std::string out = (BDDStatus) ? "BDD connection : ok." : debugInfo ;

    std::cout << out + "\n";
}

void StorageHandler::showSQLError(QSqlQuery query)
{
    QString error = query.lastError().text();
    std::cout << "[SQL ERROR] " << " : " << error.toStdString() << "\n";
}
