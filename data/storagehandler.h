#pragma once
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
#include <filesystem>

class StorageHandler
{
private:
    const char* SQLFilePath = "/home/thomas/Documents/projet/ProjetCDAA/data/data.bd";
    QSqlDatabase database;
    bool BDDStatus = false;

public:
    StorageHandler();
    void configureBDDConnection();
    void showBDDstatus();
    void setBDDStatus(const bool& status);
    bool isBDDConnection();
    void showSQLError(QSqlQuery query);
};

