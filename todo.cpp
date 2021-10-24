#include "todo.h"

ToDo::ToDo()
{
    this->date = time.getDateddmmyyyy();
}

ToDo::ToDo(std::string contenu, std::string date)
{
    this->contenu = contenu;

    if(date == "")
        this->date = time.getDateddmmyyyy();
    else
        this->date = date;
}

const std::string &ToDo::getContenu() const
{
    return contenu;
}

void ToDo::setContenu(const std::string &newContenu)
{
    contenu = newContenu;
}

const std::string &ToDo::getDate() const
{
    return date;
}

void ToDo::setDate(const std::string &newDate)
{
    date = newDate;
}

std::ostream& operator<<(std::ostream& stream, const ToDo& todo)
{
    std::string tagToDo = "@todo";
    std::string tagDate = "@date";

    return stream << tagToDo + " " + todo.contenu + " " + tagDate + " " + todo.date;
}
