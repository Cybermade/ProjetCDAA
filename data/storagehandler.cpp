#include "storagehandler.h"

StorageHandler::StorageHandler()
{
    configureBDDConnection();
    setBDDStatus(isBDDConnection());
}

void StorageHandler::configureBDDConnection()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(SQLFilePath);
}


bool StorageHandler::isBDDConnection()
{
    return std::filesystem::exists(SQLFilePath) && database.open();
}

void StorageHandler::setBDDStatus(const bool& status)
{
    BDDStatus = status;
}

void StorageHandler::showBDDstatus()
{
    std::string debugInfo = "BDD connection : not exist \n[path] = ";
    debugInfo += SQLFilePath;

    std::string out = (BDDStatus) ? "BDD connection : ok." : debugInfo ;

    std::cout << out + "\n";
}

void StorageHandler::showSQLError(QSqlQuery query)
{
    QString error = query.lastError().text();
    std::cout << "[SQL ERROR] " << " : " << error.toStdString() << "\n";
}
