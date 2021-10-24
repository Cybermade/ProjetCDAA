#pragma once
#include <ctime>
#include <string>

/**
 * @brief la classe currentTime, qui permet d'avoir la date courante au format voulu
 */
class CurrentTime
{
private:
    std::time_t t;
    std::tm* now ;

    /**
     * @brief update to the current time, c'est appelé aussi quand une autre methode
     * est appelé pour avoir le réel "timenow" et non pas le "timenow" de la creation de l'instance
     *
     */
    void update();
public:
    /**
     * @brief Constructeur par défaut
     */
    CurrentTime();

    ~CurrentTime();

    /**
     * @brief print de la date courante 'jj/mm/aaaa hh:mm:ss'
     * au format int
     */
    void showLocalTime();

    /**
     * @brief getDateddmmyyyy
     * @return la date courante au format 'jj/mm/aaaa'
     */
    std::string getDateddmmyyyy();

    /**
     * @brief getDateddmmyyyyhhmmss
     * @return la date au format 'jj/mm/aaaa hh:mm:ss'
     */
    std::string getDateddmmyyyyhhmmss();

    /**
     * @brief getDateddmmyyyyhhmm
     * @return la date au format 'jj/mm/aaaa hh:mm'
     */
    std::string getDateddmmyyyyhhmm();
};


