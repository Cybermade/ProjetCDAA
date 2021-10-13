#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "interaction.h"
#include "contact.h"


class InteractionHandler
{
private:
    std::list<Interaction> Interactions;

public:
    /**
     * @brief InteractionHandler
     */
    InteractionHandler();

    /**
     * @brief isParticipants
     * @param interaction
     * @return bool if is participants in an interaction
     */
    bool isParticipant(Interaction interaction, Contact contact);

    /**
     * @brief briefListOfParticipants
     * @param interaction
     * @return short description of participant in text
     */
    std::string briefListOfParticipants(Interaction interaction);

    void setInteractions(std::list<Interaction> interactions);

    std::list<Interaction> getAllInteractions();
    std::list<Interaction> getAllInteractionsByTitle(std::string& title);
    std::list<Interaction> getAllInteractionsByParticipant(Contact& participant);
    std::list<Interaction> getAllInteractionsByDate(CurrentTime& time);


    void deleteAnInteraction(Interaction InteractionTodelete);
    void addAnInteraction(Interaction InteractionToAdd);
    void changeParticipantOfAnInteraction(Interaction InteractionToUpdate, Contact newParticipant);


};


