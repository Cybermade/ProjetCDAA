#include "todomodel.h"

ToDoModel::ToDoModel() : StorageHandler()
{

}

bool ToDoModel::create(ToDo ToDoToAdd)
{
    bool success = false;
    QSqlQuery query;

    if(!isExist(ToDoToAdd))
    {
        query.prepare("INSERT INTO\
                       todo (contenu, date, interaction_id)\
                       VALUES (:contenu, :date, :interaction");

        bindAll(ToDoToAdd, query);

        if(query.exec())
            success = true;
        else
            showSQLError(query);
    }

    return success;
}

std::list<ToDo> ToDoModel::read(int idInteraction)
{

    std::list<ToDo> toDos;
    QSqlQuery query;
    query.prepare("SELECT * FROM interaction WHERE id = :id");
    query.bindValue(":id", idInteraction);

        if(!query.exec())
          showSQLError(query);
        else{

            ToDo toDoToFound;
            if (query.last())
                do {
                    toDoToFound = hydrate(toDoToFound, query);
                    toDos.push_back(toDoToFound);
                } while (query.previous());
        }

        return toDos;
}

bool ToDoModel::isExist(ToDo ToDoToFind)
{
    int nbRows = 0;
    QSqlQuery query;
    query.prepare("SELECT * FROM todo WHERE id = :id");
    query.bindValue(":id", ToDoToFind.getId());

    if(query.exec())
    {
        query.last();
        nbRows = query.at() + 1;
    } else
        showSQLError(query);

    return (nbRows > 0) ? true : false;
}

ToDo ToDoModel::hydrate(ToDo ToDoToHydrayte, QSqlQuery query)
{
    int id = query.value(0).toInt();
    std::string contenu = query.value(1).toString().toStdString();
    std::string date = query.value(2).toString().toStdString();
    int interaction = query.value(3).toInt();

    ToDoToHydrayte.setId(id);
    ToDoToHydrayte.setContenu(contenu);
    ToDoToHydrayte.setDate(date);
    ToDoToHydrayte.setIdInteraction(interaction);

    return ToDoToHydrayte;
}


void ToDoModel::bindAll(ToDo ToDoToBind, QSqlQuery query)
{
    query.bindValue(":id", ToDoToBind.getId());
    query.bindValue(":contenu", QString::fromStdString(ToDoToBind.getContenu()));
    query.bindValue(":date", QString::fromStdString(ToDoToBind.getDate()));
    query.bindValue("interaction", ToDoToBind.getIdInteraction());
}

void ToDoModel::printAll()
{
    QSqlQuery query("SELECT * FROM todo");

    if(!query.exec())
        showSQLError(query);
    else
    {
        while (query.next()) {
            QString id = query.value(0).toString();
            QString contenu = query.value(1).toString();
            QString date = query.value(2).toString();
            QString interaction = query.value(3).toString();

            std::cout << id.toStdString() << " | "
                      << contenu.toStdString() << " | "
                      << date.toStdString() << " | "
                      << interaction.toStdString() << " | "
                      << "\n";
        }
    }
}
