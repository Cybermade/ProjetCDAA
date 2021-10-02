#pragma once
#include <ctime>
#include <string>
class CurrentTime
{
private:
    std::time_t t;
    std::tm* now ;

    //Update to the current time
    //it's also called when you call another method to get the right "timenow"
    //and not the creation instance time
    void update();
public:
    //Default constructor
    CurrentTime();
    //Deconstructor
    ~CurrentTime();

    //Print the time dd/mm/yyyy hh:mm:ss !!!in int format
    // means you'll see 9 instead of 09 for mm for example
    void showLocalTime();



    //return a string format dd/mm/yyyy
    std::string getDateddmmyyyy();

    //return a string format dd/mm/yyyy hh:mm:ss
    std::string getDateddmmyyyyhhmmss();

    //return a string format dd/mm/yyyy hh:mm
    std::string getDateddmmyyyyhhmm();
};


