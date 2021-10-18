#pragma once
#include <ctime>
#include <string>
class CurrentTime
{
private:
    std::time_t t;
    std::tm* now ;

    //Update to the current time
    //c'est appelé aussi quand une autre methode est appelé pour avoir le réel "timenow"
    //et non pas le "timenow" de la creation de l'instance
    void update();
public:
    //Default constructor
    CurrentTime();
    //Deconstructor
    ~CurrentTime();

    //Print la date dd/mm/yyyy hh:mm:ss !!!en int format
    // qui veut dire vous allez voir 9 à la place de 09 pour mm (seulement un exemple)
    void showLocalTime();



    //retourne un string format dd/mm/yyyy de la date courrante
    std::string getDateddmmyyyy();

   //retourne un string format dd/mm/yyyy hh:mm:ss de la date courrante
    std::string getDateddmmyyyyhhmmss();

    //retourne un string format dd/mm/yyyy hh:mm de la date courrante
    std::string getDateddmmyyyyhhmm();
};


