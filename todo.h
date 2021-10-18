#pragma once
#include "string"
#include "currenttime.h"

class ToDo
{
private:
    CurrentTime time;
    std::string contenu;
    std::string date;

public:
    ToDo();
    ToDo(std::string contenu, std::string date);

    const std::string &getContenu() const;
    const std::string &getDate() const;

    void setContenu(const std::string &newContenu);
    void setDate(const std::string &newDate);

    friend std::ostream& operator<<(std::ostream& stream, const ToDo& todo);
};


