#pragma once
#include <string>
#include <QDir>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <iostream>
#include <QDir>
#include <QString>
#include <QCoreApplication>

/**
 * @brief The StorageHandler class est une classe permettant de gérer les aspects fonctionels de la BDD (connexion, erreur SQL, etc)
 */
class StorageHandler
{
private:
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

