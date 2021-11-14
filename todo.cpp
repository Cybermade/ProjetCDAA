#include "todo.h"

ToDo::ToDo()
{
    this->date = time.getDateddmmyyyy();
}

ToDo::ToDo(std::string contenu, std::string date)
{
    this->contenu = "@todo " + contenu;
    this->date = "@date ";

    if(date == "")
        this->date += time.getDateddmmyyyy();
    else
        this->date += date;
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

    return stream << todo.contenu + todo.date;
}
bool ToDo::operator==(const ToDo& T)
{
    return typeid (*this) == typeid (T)
            && this->getContenu() == T.getContenu()
            && this->getDate() == T.getDate();
}
