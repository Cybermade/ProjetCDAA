#pragma once
#include "storagehandler.h"
#include <string>
#include <iostream>
#include <QCursor>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QByteArray>

class Export : StorageHandler
{

private:
QJsonObject serializeContactsForJson();
QJsonObject serializeInteractionsForJson();
void writeInJsonFile(QJsonObject JsonObjectToWrite, QString fileToWrite);

public:
    Export();
    void exportToJson();

};

