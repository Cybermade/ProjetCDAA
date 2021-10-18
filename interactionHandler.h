#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "interaction.h"
#include "contact.h"


class InteractionHandler
{
private:
    std::list<Interaction> interactions;

public:
    /**
     * @brief InteractionHandler
     */
    InteractionHandler();

    InteractionHandler(std::list<Interaction>& interactions);

    /**
     * @brief isParticipants
     * @param interaction
     * @return bool if a participants is in an interaction
     */
    bool isParticipant(Interaction& interaction, Contact& contact);

    /**
     * @brief briefListOfParticipants
     * @param interaction
     * @return short description of participant in text
     */
    std::string briefListOfParticipants(Interaction interaction);

    /**
     * @brief setInteractions
     * @param interactions : interacations to be added
     */
    void setInteractions(std::list<Interaction>& interactions);

    /**
     * @brief getAllInteractions
     * @return list of all interactions
     */
    std::list<Interaction> getAllInteractions();

    /**
     * @brief getAllInteractionsByType
     * @param type
     * @return All interactions with the same type
     */
    std::list<Interaction> getAllInteractionsByType(std::string& type);

    /**
     * @brief getAllInteractionsByParticipant
     * @param participant
     * @return All interactions with the same participant
     */
    std::list<Interaction> getAllInteractionsByParticipant(Contact& participant);

    /**
     * @brief getAllInteractionsByDate
     * @param time
     * @return All interactions with the same date
     */
    std::list<Interaction> getAllInteractionsByDate(CurrentTime& time);


    /**
     * @brief deleteAnInteraction
     * @param InteractionTodelete
     */
    void deleteAnInteraction(Interaction& InteractionTodelete);

    /**
     * @brief addAnInteraction
     * @param InteractionToAdd
     */
    void addAnInteraction(Interaction& InteractionToAdd);

    /**
     * @brief changeParticipantOfAnInteraction
     * @param InteractionToUpdate
     * @param newParticipant
     */
    void changeParticipantOfAnInteraction(Interaction& InteractionToUpdate, Contact& newParticipant);

};


