#pragma once
#include "currenttime.h"
#include <string>
#include <ctime>
#include <list>
#include <typeinfo>

/**
 * @brief La classe Contact
 */
class Contact
{
private:
    CurrentTime T;//objet CurrentTime
    std::string m_lastname;//nom
    std::string m_firstname;//prenom
    std::string m_company;//entreprise
    std::string m_mail;//mail
    std::string m_phonenumber;//telephone
    std::string m_photo;//photo
    std::string m_creationdate;//date de creation
    std::string m_modificationdate;//dernière date de modification

    /**
     * @brief change la dernière date de modification
     */
    void updateModificationDate();

public:
    /**
     * @brief Constructeur par défaut
     */
    Contact();

    ~Contact();

    /**
     * @brief Constructeur avec paramètre
     * @param name : nom du contact
     * @param firstname : prenom du contact
     * @param company : entreprise du contact
     * @param mail : mail du contact
     * @param phonenumber : numéro de téléphone du contact
     * @param photo : url de la photo du contact
     */
    Contact(std::string& name,std::string& firstname,std::string& company
             ,std::string& mail,std::string& phonenumber,
             std::string& photo);

    /**
     * @brief Editer un contact et ses informations
     * @param name : nom du contact
     * @param firstname : prenom du contact
     * @param company : entreprise du contact
     * @param mail : mail du contact
     * @param phonenumber : numéro de téléphone du contact
     * @param photo : url de la photo du contact
     */
    void edit(std::string& name,std::string& firstname,std::string& company
         ,std::string& mail,std::string& phonenumber,
         std::string& photo);


    /**
     * @brief getLastName
     * @return le nom de famille en string
     */
    std::string getLastName() const;

    /**
     * @brief getFirstName
     * @return le prénom en string
     */
    std::string getFirstName() const;

    /**
     * @brief getCompany
     * @return l'entreprise en string
     */
    std::string getCompany() const;

    /**
     * @brief getMail
     * @return le mail en string
     */
    std::string getMail() const;

    /**
     * @brief getPhoneNumber
     * @return le numéro de téléphone en string
     */
    std::string getPhoneNumber() const;

    /**
     * @brief getPhoto
     * @return l'uri de la photo en string
     */
    std::string getPhoto() const;

    /**
     * @brief getCreationDate
     * @return la date de création en string
     */
    std::string getCreationDate() const;

    /**
     * @brief getModificationDate
     * @return la date de modification en string
     */
    std::string getModificationDate() const;

    /**
     * @brief setLastName
     * @param name : le nouveau nom du contact
     */
    void setLastName(std::string& name);

    /**
     * @brief setFirstName
     * @param firstname : le nouveau prenom du contact
     */
    void setFirstName(std::string& firstname);

    /**
     * @brief setCompany
     * @param company : la nouvelle entreprise du contact
     */
    void setCompany(std::string& company);

    /**
     * @brief setMail
     * @param mail : le nouveau mail du contact
     */
    void setMail(std::string& mail);

    /**
     * @brief setPhoneNumber
     * @param phonenumber : le nouveau numéro de téléphone du contact
     */
    void setPhoneNumber(std::string& phonenumber);

    /**
     * @brief setPhoto
     * @param photo : la nouvelle uri de la photo du contact
     */
    void setPhoto(std::string& photo);

    /**
     * @brief setCreationdate
     * @param newCreationdate :  la nouvelle date de création du contact
     */
    void setCreationdate(const std::string &newCreationdate);

    /**
     * @brief setModificationdate
     * @param newModificationdate : la nouvelle date de modification du contact
     */
    void setModificationdate(const std::string &newModificationdate);


    /**
     * @brief operator << override : permet d'afficher un contact dans la console
     * @param stream le flux à retourner
     * @param contact à afficher
     * @return stream : le flux
     */
    friend std::ostream& operator<<(std::ostream& stream, const Contact& contact);

    /**
     * @brief operator == override : permet de comparer deux contact
     * @param b : le contact à comparé
     * @return bool : true | false
     */
    bool operator==(const Contact& b);




};
