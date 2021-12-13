#pragma once
#include "storagehandler.h"
#include "logic/interaction.h"
#include "contactmodel.h"
#include <QVariant>
#include <QDebug>
#include<string>

/**
 * @brief The InteractionModel : ensemble de méthodes  pour manipuler les données des interactions entre la BD et l'application
 */
class InteractionModel : public StorageHandler
{
private:
    /**
     * @brief hydrate permet de remplir un objet interaction à partir d'une requête SQL
     * @param interactionToHydrate l'interaction à remplir
     * @param query la requête à utiliser pour remplir l'interaction
     * @return l'interaction remplie
     */
    Interaction hydrate(Interaction interactionToHydrate, QSqlQuery query);

    /**
     * @brief bindAll permet de bind (relier) autotmatiquement TOUS les champs pour une requête préparé
     * @param interactionToBind est l'interaction delaquelle provienne les informations à bind
     * @param query est la requête à bind
     */
    void bindAll(Interaction interactionToBind, QSqlQuery query);

public:
    /**
     * @brief InteractionModel
     */
    InteractionModel();

    /**
     * @brief isExist permet de vérifier si une interaction existe déjà ou non dans la BDD
     * @param interactionToFind l'interaction à cherché
     * @return True | False en fonction du résultat de la requête
     */
    bool isExist(Interaction interactionToFind);

    /**
     * @brief create permet d'ajouter une interaction à la base de données
     * @param interactionToAdd l'interaction à ajouter
     * @return  True | False en fonction du résultat de la requête
     */
    bool create(Interaction interactionToAdd);

    /**
     * @brief read permet de récupérer toutes les interactions dans la base de données
     * @return une liste d'objet interaction
     */
    std::list<Interaction> read();

    /**
     * @brief update permet de mettre à jour les informations d'un interaction dans la base de données
     * @param oldInteraction les ancinnes informations de l'interaction
     * @param newInteraction les nouvelles informations de l'interaction
     * @return True | False en fonction du résultat de la requête
     */
    bool update(Interaction oldInteraction, Interaction newInteraction);

    /**
     * @brief deletePermanently Permet de supprimer définitivement une interaction de la base de données
     * @param interactionToDelete l'interaction à supprimer
     * @return  True | False en fonction du résultat de la requête
     */
    bool deletePermanently(Interaction interactionToDelete);

    /**
     * @brief findByName permet de trouver une interaction par son nom
     * @param nameToFind le nom de l'interaction à trouver
     * @return
     */
    Interaction findByName(std::string nameToFind);

    /**
     * @brief printAll permet d'afficher toutes les interactions de la base de données en mode console
     */
    void printAll();
};

