#pragma once
#include <string>
#include "logic/contact.h"
#include "storagehandler.h"
#include <QVariant>
#include <QDebug>
#include<string>

/**
 * @brief ContactModel : ensemble de méthode pour manipuler les données des Contact entre la BD et l'application
 */
class ContactModel : public StorageHandler
{

private:
    /**
     * @brief hydrate permet de créer un objet contact à partir d'une requête SQL
     * @param contactToHydrate le contact à créer
     * @param query la requête permettant sa création
     * @return le contact créé
     */
    Contact hydrate(Contact contactToHydrate, QSqlQuery query);

    /**
     * @brief bindAll permet de bind (relier) autotmatiquement TOUS les champs pour une requête préparé
     * @param contactToBind le contact duquel il faut prendre les informations à bind
     * @param query la requête à préparer
     */
    void bindAll(Contact contactToBind, QSqlQuery query);

public:

    /**
     * @brief ContactModel
     */
    ContactModel();

    /**
     * @brief isExist vérifie si un contact existe déjà dans la base de données
     * @param ContactToFind le contact à chercher dans la base de données
     * @return True | False s'il on trouve le contact où non
     */
    bool isExist(Contact ContactToFind);

    /**
     * @brief create permet d'ajouter un contact à la base de données
     * @param ContactToAdd le contact à ajouter
     * @return True | False si l'opération à réussie
     */
    bool create(Contact ContactToAdd);

    /**
     * @brief read permet de récupérer les contacts dans la base de données
     * @return Un liste des contacts trouvés
     */
    std::list<Contact> read();

    /**
     * @brief update Permet de mettre à jour un contact dans la base de données
     * @param oldContact les anciennes informations du contact
     * @param newContact les nouvelles informations du contact
     * @return True | False si l'opération à réussie
     */
    bool update(Contact oldContact, Contact newContact);

    /**
     * @brief deletePermanently supprime un contact de la base de données définitivement
     * @param ContactToDelete le contact à supprimer
     * @return True | False si l'opération à réussie
     */
    bool deletePermanently(Contact ContactToDelete);

    /**
     * @brief findByName permet de trouver un contact par son nom
     * @param nameToFind le nom du contact à trouver
     * @return Le contact trouvé (vide s'il n'existe pas)
     */
    Contact findByName(std::string nameToFind);

    /**
     * @brief findById permet de trouver un contact par son id
     * @param id du contact à trouver
     * @return Le contact trouvé (vide s'il n'existe pas)
     */
    Contact findById(int id);

    /**
     * @brief printAll permet d'afficher tous les contacts dans la base de données en mode console
     */
    void printAll();

};

