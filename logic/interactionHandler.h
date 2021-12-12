#pragma once
#include <string>
#include <list>
#include <algorithm>
#include "logic/interaction.h"
#include "logic/contact.h"
#include "logic/todo.h"
#include "data/interactionmodel.h"
#include "data/todomodel.h"


/**
 * @brief Classe InteractionHandler
 */
class InteractionHandler
{
private:
    std::list<Interaction> interactions;
    InteractionModel linkWithBDD;
    ToDoModel toDoLinkWithBDD;

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
    /**
     * @brief InteractionById
     * @param id
     * @return Interaction
     */
    Interaction InteractionById(unsigned int id);
    /**
     * @brief deleteInteractionById
     * @param id
     */
    void deleteInteractionById(unsigned int id);
    /**
     * @brief editInteraction
     * @param id
     * @param type
     * @param titre
     * @param p
     * @param note
     */
    void editInteraction(unsigned int id,std::string& type,
                         std::string& titre,Contact p
                         ,std::string& note);
    /**
     * @brief editInteraction
     * @param id
     * @param type
     * @param titre
     * @param note
     */
    void editInteraction(unsigned int id,std::string& type,
                         std::string& titre
                         ,std::string& note);
    /**
     * @brief addToDoForInteraction
     * @param id
     * @param add
     */
    void addToDoForInteraction(unsigned int id, ToDo add);
    /**
     * @brief deleteToDoForInteraction
     * @param id
     * @param D
     */
    void deleteToDoForInteraction(unsigned int id, ToDo D);

    std::list<Interaction> fetchBDD();
};


