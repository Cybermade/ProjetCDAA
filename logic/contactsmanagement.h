#pragma once
#include <vector>
#include <list>
#include <string>
#include "logic/contact.h"
#include "logic/currenttime.h"
#include "data/contactmodel.h"

/**
 * @brief La classe contactManagement
 */
class Contactsmanagement
{
private:
    CurrentTime T;//Simple class de dateManagement
    std::string m_datelastdelete;//Date de la dernière suppresion
    std::list<Contact> m_contactsmanagement;//Contacts management
    ContactModel linkWithBDD; //lien avec la BDD




public:
    /**
     * @brief Constructeur par défaut
     */
    Contactsmanagement();
    ~Contactsmanagement();

    /**
     * @brief ajout d'un contact à la liste de contact
     * @param c : le contact à ajouter
     */
    void addContact(const Contact& c);

    /**
     * @brief création + ajout d'un "contact" à partir des informations données
     * @param name : nom du contact
     * @param firstname : prénom du contact
     * @param company : entreprise du contact
     * @param mail : mail du contact
     * @param phonenumber : numéro de téléphone du contact
     * @param photo : uri de la photo du contact
     */
    void addContact(std::string name, std::string firstname, std::string company, std::string mail, std::string phonenumber, std::string photo);

    /**
     * @brief modifie un contact en fonction de sa place (id) dans la liste
     * @param id : place dans la liste du contact
     * @param name : nom du contact
     * @param firstname : prénom du contact
     * @param company : entreprise du contact
     * @param mail : mail du contact
     * @param phonenumber : numéro de téléphone du contact
     * @param photo : uri de la photo du contact
     */
    void editContact(unsigned int id,std::string& name,
                    std::string& firstname,std::string& company
                     ,std::string& mail,std::string& phonenumber,
                     std::string& photo);

    /**
     * @brief Affiche toutes les infos de tous les contacts
     */
    void showSheetAll()const;

    /**
     * @brief Supprime un contact en fonction de sa position dans la liste
     * @param id
     */
    void deleteContactById(unsigned int id);

    /**
     * @brief Supprime tous les contacts correspondant à c
     * @param c : le contact à supprimer
     */
    void deleteContact(const Contact& c);

    /**
     * @brief operator + overrride
     * @param c : le contact à ajouter à la liste des contacts
     * @return Une instance de ContactsManagement
     */
    Contactsmanagement operator+(const Contact& c);

    /**
     * @brief operator += overrride
     * @param c : le contact à ajouter à la liste des contacts
     * @return Une instance de ContactsManagement
     */
    Contactsmanagement operator+=(const Contact& c);

    /**
     * @brief operator - override
     * @param c : le contact à enlever de la liste
     * @return Une instance de ContactsManagement
     */
    Contactsmanagement operator-(const Contact& c);

    /**
     * @brief operator -= override
     * @param c : le contact à enlever de la liste
     * @return Une instance de ContactsManagement
     */
    Contactsmanagement operator-=(const Contact& c);

    /**
     * @brief Clear la liste
     */
    void deleteAll();
    /**
     * @brief ContactById
     * @param id
     * @return
     */
    Contact ContactById(unsigned int id);
    /**
     * @brief getContactsList
     * @return
     */
    std::list<Contact> getContactsList();

    std::list<Contact> fetchBDD();

};
