#include "interactionHandler.h"

InteractionHandler::InteractionHandler()
{
    this->interactions = fetchBDD();
}

InteractionHandler::InteractionHandler(std::list<Interaction>& interactions)
{
    this->interactions = interactions;
}

void InteractionHandler::addAnInteraction(Interaction &InteractionToAdd)
{
    this->interactions.push_back(InteractionToAdd);
    this->linkWithBDD.create(InteractionToAdd);
}

void InteractionHandler::deleteAnInteraction(Interaction &InteractionTodelete)
{
    this->interactions.remove(InteractionTodelete);
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


void InteractionHandler::setInteractions(std::list<Interaction>& newInteractions)
{
    this->interactions = newInteractions;
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

void InteractionHandler::showAllInteractions()
{
    for(Interaction &interactionToShow : this->interactions)
    {
        std::cout << interactionToShow;
        std::cout << "\n";
    }
}

Interaction InteractionHandler::InteractionById(unsigned int id)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            return(*itr);
        }
        else{
            throw id;
        }
    }
    catch(unsigned int id)
    {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }

}

void InteractionHandler::deleteInteractionById(unsigned int id)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            interactions.erase(itr);

        }
        else{
            throw id;
        }
    }
    catch(unsigned int id)
    {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }
}

void InteractionHandler::editInteraction(unsigned int id, std::string &type, std::string &titre, Contact p, std::string &note)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            Interaction oldInteraction = *itr; //interaction de base
            itr->edit(type,titre,p,note);
            Interaction newInteraction = *itr; //nouvelle interaction à partir de l'édition faite par l'utilisateur
            this->linkWithBDD.update(oldInteraction, newInteraction);

            std::cout << oldInteraction.getParticipant().getId();
        }
        else
        {
            throw id;
        }
    }
    catch (unsigned int id) {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }
}

void InteractionHandler::editInteraction(unsigned int id, std::string &type, std::string &titre, std::string &note)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            Interaction oldInteraction = *itr; //interaction de base
            Contact oldPerson = itr->getParticipant(); //contact à garder de l'interaction de base
            itr->edit(type,titre,note);
            Interaction newInteraction = *itr; //nouvelle interaction à partir de l'édition faite par l'utilisateur
            this->linkWithBDD.update(oldInteraction, newInteraction);
        }
        else
        {
            throw id;
        }
    }
    catch (unsigned int id) {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }
}

void InteractionHandler::addToDoForInteraction(unsigned int id, ToDo add)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            itr->addToDo(add);
        }
        else
        {
            throw id;
        }
    }
    catch (unsigned int id) {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }
}

void InteractionHandler::deleteToDoForInteraction(unsigned int id, ToDo D)
{
    try {
        if ( interactions.size() > id )
        {
            std::list<Interaction>::iterator itr = interactions.begin();
            std::advance(itr,id);
            itr->deleteToDo(D);
        }
        else
        {
            throw id;
        }
    }
    catch (unsigned int id) {
        std::cout << "The Size Of The List Of Interactions Should Be Greater Than The Id"<<std::endl;
    }
}

std::list<Interaction> InteractionHandler::fetchBDD()
{
    std::list<Interaction> interactionFromBDD = this->linkWithBDD.read();
    return interactionFromBDD;

}
