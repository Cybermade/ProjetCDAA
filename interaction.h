#pragma once
#include "currenttime.h"
#include "contact.h"
#include <string>
#include <ctime>
#include <list>
#include <iostream>

/**
 * @brief la classe interaction
 */
class Interaction
{
private:
    CurrentTime time;
    std::string type;
    std::string title;
    std::string date;
    Contact participant;
    std::string note;
    std::string modficationDate = "No modification";

public:
    /**
     * @brief Constructeur avec paramètres
     * @param type d'intéraction
     * @param title : titre de l'interaction
     * @param participant est le contact qui participe à l'intéraction
     * @param note
     */
    Interaction(std::string& type, std::string& title, Contact& participant, std::string& note);

    /**
     * @brief Constructeur par défaut
     */
    Interaction();

    ~Interaction();

    /**
     * @brief Modifier une interaction
     * @param type d'intéraction
     * @param title : titre de l'interaction
     * @param participant est le contact qui participe à l'intéraction
     * @param note
     * @param date de mofication
     */
    void edit(std::string& type, std::string& title, Contact& participant, std::string& note, std::string date);

    /**
     * @brief getTitle
     * @return le titre de l'interaction
     */
    std::string getTitle() const;

    /**
     * @brief getDate
     * @return la date de l'interaction
     */
    std::string getDate() const;

    /**
     * @brief getParticipants
     * @return le participant de l'interaction
     */
    Contact getParticipant() const;

    /**
     * @brief getNote
     * @return la note de l'interaction
     */
    std::string getNote() const;

    /**
     * @brief getType
     * @return le type d'interaction
     */
    std::string getType() const;

    /**
     * @brief getModificationDate
     * @return la dernière date de modification
     */
    std::string getModificationDate() const;

    /**
     * @brief setTitle
     * @param newTitle
     */
    void setTitle(std::string& newTitle);

    /**
     * @brief setParticipants
     * @param newParticipant
     */
    void setParticipants(Contact& newParticipant);

    /**
     * @brief setNote
     * @param newNote
     */
    void setNote(std::string& newNote);

    /**
     * @brief setType
     * @param type
     */
    void setType(std::string& newType);

    /**
     * @brief Met à jour la date dernière date de
     * modification de l'intéraction à la date courante
     */
    void updateModificationDate();



 /**
 * @brief operator <<
 * @return ToString of class Interaction
 */
friend std::ostream& operator<<(std::ostream& stream, const Interaction& Interaction);
};

