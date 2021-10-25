#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "interaction.h"
#include "contact.h"

/**
 * @brief Classe InteractionHandler
 */
class InteractionHandler
{
private:
    std::list<Interaction> interactions;

public:
    /**
     * @brief Constructeur par défaut
     */
    InteractionHandler();

    /**
     * @brief Constructeur avec paramètre
     * @param liste des interacations
     */
    InteractionHandler(std::list<Interaction>& interactions);

    /**
     * @brief determine si un contact / participant est dans concerné par une interaction donnée^
     * @param interaction
     * @return true | false si un participant est dans une interaction
     */
    bool isParticipant(Interaction& interaction, Contact& contact);

    /**
     * @brief retourne une compilation de courtes descriptions de chaque participant d'une interaction
     * @param interaction
     * @return Courtes descriptions de chaque participant d'une interaction
     */
    std::string briefListOfParticipants(Interaction interaction);

    /**
     * @brief setInteractions
     * @param newInteractions
     */
    void setInteractions(std::list<Interaction>& newInteractions);

    /**
     * @brief Retourne sans tri les interactions
     * @return toutes les interactions de l'application
     */
    std::list<Interaction> getAllInteractions();

    /**
     * @brief Permet d'avoir toutes les interactions ayant le même type
     * @param type
     * @return Toutes les interactions avec le même type
     */
    std::list<Interaction> getAllInteractionsByType(std::string& type);

    /**
     * @brief Permet d'avoir toutes les interactions avec le même participant (ou contact)
     * @param participant
     * @return Toutes les interactions avec le même participant
     */
    std::list<Interaction> getAllInteractionsByParticipant(Contact& participant);

    /**
     * @brief Permet d'avoir toutes les interactions avec la même date
     * @param time
     * @return Toutes les interactions avec la même date
     */
    std::list<Interaction> getAllInteractionsByDate(std::string& time);


    /**
     * @brief Permet de supprimer une interaction donnée de l'application
     * @param InteractionTodelete
     */
    void deleteAnInteraction(Interaction& InteractionTodelete);

    /**
     * @brief Permet d'ajouter une interaction à l'application
     * @param InteractionToAdd
     */
    void addAnInteraction(Interaction& InteractionToAdd);

    /**
     * @brief Permet d'afficher toutes les interactions en mode console
     */
    void showAllInteractions();

};


