#include "interaction.h"
#include "interactionHandler.h"

Interaction::Interaction()
{
    this->type = "Undefined";
    this->title = "Undefined";
    this->date = time.getDateddmmyyyy();
    this->note = "Undefined";
}

Interaction::Interaction(std::string& type, std::string& title, Contact& participant, std::string& note)
{
    this->type = type;
    this->title = title;
    this->date = time.getDateddmmyyyy();
    this->note = note;
    this->Participant = participant;
}

Interaction::~Interaction(){}

std::string Interaction::getDate() const
{
    return this->date;
}

std::string Interaction::getTitle() const
{
    return this->title;
}

std::string Interaction::getNote() const
{
    return this->note;
}

Contact Interaction::getParticipant() const
{
    return this->Participant;
}

void Interaction::setType(std::string &type)
{
    this->type = type;
}

void Interaction::setNote(std::string &note)
{
    this->note = note;
}

void Interaction::setTitle(std::string &title)
{
    this->title = title;
}

void Interaction::setParticipants(Contact &participant)
{
    this->Participant = participant;
}

std::ostream& operator<<(std::ostream& stream, const Interaction& interaction)
{
  InteractionHandler interactionHandler = InteractionHandler();

  return stream <<  interaction.type +
                    " : [title] --> " + interaction.title + "; "
                    " [date] --> " + interaction.date + "; "
                    " [Note] --> " + interaction.note + "; "
                    " [participant] --> " + interactionHandler.briefListOfParticipants(interaction) +
                    ".\n";
}
