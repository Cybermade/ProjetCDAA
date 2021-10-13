#include "interactionHandler.h"

InteractionHandler::InteractionHandler()
{

}

InteractionHandler::InteractionHandler(std::list<Interaction>& interactions)
{
    this->Interactions = interactions;
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
        participantsInfos += participant.getFirstName() + " " + participant.getName();

    return participantsInfos;
}

void InteractionHandler::setInteractions(std::list<Interaction>& interactions)
{
    this->Interactions = interactions;
}

std::list<Interaction> InteractionHandler::getAllInteractions()
{
    return this->Interactions;
}

std::list<Interaction> InteractionHandler::getAllInteractionsByType(std::string& type)
{

}
