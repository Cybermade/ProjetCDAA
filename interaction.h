#pragma once
#include "currenttime.h"
#include "contact.h"
#include <string>
#include <ctime>
#include <list>
#include <iostream>

/**
 * @brief The Interaction class
 */
class Interaction
{
private:
    CurrentTime time;
    std::string type;
    std::string title;
    std::string date;
    Contact Participant;
    std::string note;

public:
    /**
     * @brief Interaction constructor with params
     * @param type
     * @param title
     * @param participants
     * @param note
     */
    Interaction(std::string& type, std::string& title, Contact& participant, std::string& note);

    /**
     * @brief Interaction default constructor
     */
    Interaction();
    /**
     * @brief ~Interaction destructor
     */
    ~Interaction();

    // GETTER & SETTER
    /**
     * @brief getTitle
     * @return title : title of the interaction
     */
    std::string getTitle() const;
    /**
     * @brief getDate
     * @return date : date of the intereaction
     */
    std::string getDate() const;
    /**
     * @brief getParticipants
     * @return participant of the interaction
     */
    Contact getParticipant() const;
    /**
     * @brief getNote
     * @return note : note of the interaction
     */
    std::string getNote() const;

    /**
     * @brief getType
     * @return type : type of interaction
     */
    std::string getType() const;

    /**
     * @brief setTitle
     * @param title : title to change
     */
    void setTitle(std::string& title);
    /**
     * @brief setParticipant
     * @param participant : participant of the interactions
     */
    void setParticipants(Contact& participant);
    /**
     * @brief setNote
     * @param note : note of the interaction
     */
    void setNote(std::string& note);

    /**
     * @brief setInteractionName
     * @param name : name of the interaction
     */
    void setType(std::string& type);



 /**
 * @brief operator <<
 * @return ToString of class Interaction
 */
friend std::ostream& operator<<(std::ostream& stream, const Interaction& Interaction);
};

