#pragma once
#include "storagehandler.h"
#include <string>
#include <iostream>
#include <QCursor>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QByteArray>

/**
 * @brief The Export class sert à exporter les données de la base de données (En JSON seulement pour l'instant)
 */
class Export : StorageHandler
{

private:
 /**
 * @brief serializeContactsJson permet de transposer les contacts de la BDD en objet JSON
 * @return l'objet JSON des contacts
 */
QJsonObject serializeContactsJson();

/**
 * @brief serializeContactsJson permet de transposer les interactions de la BDD en objet JSON
 * @return l'objet JSON des interactions
 */
QJsonObject serializeInteractionsJson();

/**
 * @brief serializeContactsJson permet de transposer les todos de la BDD en objet JSON
 * @return l'objet JSON des todos
 */
QJsonObject serializeToDoJson();

/**
 * @brief writeInJsonFile Permet d'écrire un objet JSON dans un fichier
 * @param JsonObjectToWrite l'objet JSON à écrire
 * @param fileToWrite le fichier dans lequel écrire
 */
void writeInJsonFile(QJsonObject JsonObjectToWrite, QString fileToWrite);

public:
    Export();

    /**
     * @brief exportToJson permet d'exporter la base de données dans un fichier JSON
     */
    void exportToJson();

};

