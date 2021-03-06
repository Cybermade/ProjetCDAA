#pragma once
#include "string"
#include "logic/currenttime.h"
#include <typeinfo>

/**
 * @brief La classe ToDo
 */
class ToDo
{
private:
    CurrentTime time;
    int id;
    int idInteraction;
    std::string contenu;
    std::string date;

public:
    /**
     * @brief Constructeur par défaut
     */
    ToDo();

    /**
     * @brief Constructeur avec paramètre
     * @param le contenu du ToDo
     * @param la date du ToDo
     */
    ToDo(std::string contenu, std::string date = "");

    /**
     * @brief getContenu
     * @return le contenu en string
     */
    const std::string &getContenu() const;

    /**
     * @brief getDate
     * @return la date en string
     */
    const std::string &getDate() const;

    /**
     * @brief setContenu
     * @param newContenu
     */
    void setContenu(const std::string &newContenu);

    /**
     * @brief setDate
     * @param newDate
     */
    void setDate(const std::string &newDate);

    /**
     * @brief operator << override
     * @param stream : le flux à retourner
     * @param todo : le todo à afficher
     * @return stream
     */
    friend std::ostream& operator<<(std::ostream& stream, const ToDo& todo);
    /**
     * @brief operator ==
     * @param T
     * @return bool
     */
    bool operator==(const ToDo& T);

    /**
     * @brief getId
     * @return
     */
    int getId() const;

    /**
     * @brief setId
     * @param newId
     */
    void setId(int newId);

    /**
     * @brief getIdInteraction
     * @return
     */
    int getIdInteraction() const;

    /**
     * @brief setIdInteraction
     * @param newIdInteraction
     */
    void setIdInteraction(int newIdInteraction);
};


