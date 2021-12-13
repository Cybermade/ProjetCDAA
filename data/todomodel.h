#pragma once
#include <string>
#include "logic/todo.h"
#include "storagehandler.h"
#include <QVariant>
#include <QDebug>
#include<string>


/**
 * @brief The ToDoModel : ensemble de méthode pour manipuler les ToDo entre la BDD et l'application
 */
class ToDoModel : StorageHandler
{
private:
    /**
     * @brief hydrate permet de remplir un todo à partir d'une requête SQL
     * @param ToDoToHydrayte l'objet Todo à remplir
     * @param query la requête pour remplir l'objet
     * @return l'objet rempli depuis la base de données
     */
    ToDo hydrate(ToDo ToDoToHydrayte, QSqlQuery query);

    /**
     * @brief bindAll permet de bind (relier) automatiquement TOUS les champs pour une requête preparée
     * @param ToDoToBind le todo duquel il faut prendre les informations à bind
     * @param query la requête à préparer
     */
    void bindAll(ToDo ToDoToBind, QSqlQuery query);

    /**
     * @brief isExist permet de vérifier si un todo existe déjà ou non dans la base de données
     * @param ToDoToFind le todo à chercher
     * @return True | False en fonction du résultat de la requête
     */
    bool isExist(ToDo ToDoToFind);

public:
    /**
     * @brief ToDoModel
     */
    ToDoModel();

    /**
     * @brief create permet d'ajouter un todo à la base de données
     * @param ToDoToAdd le todo à ajouter
     * @return  True | False en fonction du résultat de la requête
     */
    bool create(ToDo ToDoToAdd);

    /**
     * @brief read permet de récupérer les ToDo d'une interaction donnée
     * @param idInteraction l'id de l'interaction donnée
     * @return une liste de todo corespondants à l'interaction donnée
     */
    std::list<ToDo> read(int idInteraction);

    /**
     * @brief deletePermanently permet de supprimer définitivement un ToDo de la base de données
     * @param ToDoToDelete le todo à supprimer de la base de données
     * @return True | False en fonction du résultat de la requête
     */
    bool deletePermanently(ToDo ToDoToDelete);

    /**
     * @brief printAll permet d'afficher tous les todo dans la base de données dans le terminal
     */
    void printAll();
};
