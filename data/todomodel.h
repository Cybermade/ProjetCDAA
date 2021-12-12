#pragma once
#include <string>
#include "logic/todo.h"
#include "storagehandler.h"
#include <QVariant>
#include <QDebug>
#include<string>



class ToDoModel : StorageHandler
{
private:


    ToDo hydrate(ToDo ToDoToHydrayte, QSqlQuery query);
    void bindAll(ToDo ToDoToBind, QSqlQuery query);
    bool isExist(ToDo ToDoToFind);

public:
    ToDoModel();
    bool create(ToDo ToDoToAdd);
    std::list<ToDo> read(int idInteraction);
    bool update(ToDo oldToDo, ToDo newToDo);
    bool deletePermanently(ToDo ToDoToDelete);
    ToDo findByName(std::string nameToFind);
    void printAll();
};
