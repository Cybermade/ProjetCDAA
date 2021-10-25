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
    this->participant = participant;
}

Interaction::~Interaction(){}

void Interaction::edit(std::string& type, std::string& title, Contact& participant, std::string& note, std::string date)
{
   this->type = type;
   this->title = title;
   this->participant = participant;
   this->note = note;
   this->date = date;

   updateModificationDate();
}

void Interaction::addToDo(ToDo ToDoToAdd)
{
    this->todos.push_back(ToDoToAdd);
}

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
    return this->participant;
}

std::string Interaction::getType() const
{
    return this->type;
}

std::string Interaction::getModificationDate() const
{
    return this->modficationDate;
}

std::list<ToDo> Interaction::getToDos() const
{
    return this->todos;
}

void Interaction::setType(std::string &newType)
{
    this->type = newType;
}

void Interaction::setNote(std::string &newNote)
{
    this->note = newNote;
}

void Interaction::setTitle(std::string &newTitle)
{
    this->title = newTitle;
}

void Interaction::setParticipants(Contact &newParticipant)
{
    this->participant = newParticipant;
}

void Interaction::setTodos(std::list<ToDo> newToDos)
{
    this->todos = newToDos;
}

void Interaction::updateModificationDate()
{
    CurrentTime time = CurrentTime();
    this->modficationDate = time.getDateddmmyyyy();
}

std::ostream& operator<<(std::ostream& stream, const Interaction& interaction)
{
  InteractionHandler interactionHandler = InteractionHandler();

  std::list<ToDo> todos = interaction.getToDos();
  std::string todosInString = "";

  if(todos.empty())
      todosInString = "no todo";
  else
      for(ToDo &todo : todos)
        todosInString += todo.getContenu() + " " + todo.getDate() + ", ";



  return stream <<  interaction.getType() + " : \n" +
                    " [title] --> " + interaction.getTitle() + "; \n" +
                    " [date] --> " + interaction.getDate() + "; \n" +
                    " [note] --> " + interaction.getNote() + "; \n" +
                    " [todo] --> " + todosInString + "; \n" +
                    " [participant] --> " + interactionHandler.briefListOfParticipants(interaction) + "; \n" +
                    " [modification date] --> " +interaction.getModificationDate() + ". \n";
}

bool Interaction::operator==(const Interaction &interacationToCompare)
{
    return this->type == interacationToCompare.type &&
           this->date == interacationToCompare.date &&
           this->participant == interacationToCompare.participant &&
           this->title == interacationToCompare.title;
}
