#include "interactionHandler.h"

InteractionHandler::InteractionHandler()
{

}


bool InteractionHandler::isParticipant(Interaction interaction, Contact contact)
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
