#include "interactionHandler.h"

InteractionHandler::InteractionHandler()
{

}

InteractionHandler::InteractionHandler(std::list<Interaction>& interactions)
{
    this->interactions = interactions;
}

void InteractionHandler::addAnInteraction(Interaction &InteractionToAdd)
{
    this->interactions.push_back(InteractionToAdd);
}

bool InteractionHandler::isParticipant(Interaction& interaction, Contact& contact)
{
   return interaction.getParticipant() == contact;
}

std::string InteractionHandler::briefListOfParticipants(Interaction interaction)
{
    Contact participant = interaction.getParticipant();
    std::string participantsInfos = "";

    if(this->isParticipant(interaction, participant))
        participantsInfos += participant.getFirstName() + " " + participant.getLastName();

    return participantsInfos;
}

void InteractionHandler::setInteractions(std::list<Interaction>& interactions)
{
    this->interactions = interactions;
}

std::list<Interaction> InteractionHandler::getAllInteractions()
{
    return this->interactions;
}



std::list<Interaction> InteractionHandler::getAllInteractionsByType(std::string& type)
{
    std::list<Interaction> interactionByType;
    for(const Interaction& interaction : this->interactions)
        if(interaction.getType() == type)
            interactionByType.push_back(interaction);
    return interactionByType;
}

std::list<Interaction> InteractionHandler::getAllInteractionsByParticipant(Contact &participant)
{
    std::list<Interaction> interactionByParticipant;
    for(const Interaction& interaction : this->interactions)
        if(interaction.getParticipant() == participant)
            interactionByParticipant.push_back(interaction);
    return interactionByParticipant;
}

std::list<Interaction> InteractionHandler::getAllInteractionsByDate(std::string &time)
{
    std::list<Interaction> interactionByDate;
    for(const Interaction& interaction : this->interactions)
        if(interaction.getDate() == time)
            interactionByDate.push_back(interaction);
    return interactionByDate;
}
