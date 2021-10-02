
#include <ctime>
#include <iostream>
#include <string>
#include "currenttime.h"
CurrentTime::CurrentTime()
    :t(std::time(0)),now(std::localtime(&t))
{

    now->tm_year += 1900;//tm_year gives years from 1900 that's why we add 1900
    now->tm_mon += 1;//+1 because tm->mon(from 0(january) to 11)

}
void CurrentTime::update()
{
    this->t = std::time(0);
    this->now = std::localtime(&t);
    this->now->tm_year += 1900;
    this->now->tm_mon += 1;


}
void CurrentTime::showLocalTime()
{           update();
            std::cout << now->tm_mday  << '/'
                     << now->tm_mon  << '/'
                     <<  now->tm_year <<" "
                       <<  now->tm_hour<<":"
                      << now->tm_min<<":"
                      << now->tm_sec
                     << "\n";
}
std::string CurrentTime::getDateddmmyyyy()
{   update();
    std::string date="";
    if (now->tm_mday <= 9)
    {
        date = "0"+std::to_string(now->tm_mday);
    }
    else
    {
        date = std::to_string(now->tm_mday);
    }
    date += "/";
    if (now->tm_mon <= 9)
    {
        date = date+ "0"+std::to_string(now->tm_mon);
    }
    else
    {
        date = date + std::to_string(now->tm_mon);
    }
    date += "/";
    date += std::to_string(now->tm_year);

    return date;



}
std::string CurrentTime::getDateddmmyyyyhhmmss()
{   update();
    std::string date = this->getDateddmmyyyy();
    date += " ";
    if(now->tm_hour <= 9)
    {
        date = date +"0"+std::to_string(now->tm_hour);
    }
    else
    {
        date = date + std::to_string(now->tm_hour);
    }
    date +=":";
    if(now->tm_min <= 9)
    {
        date = date +"0"+std::to_string(now->tm_min);
    }
    else
    {
        date = date + std::to_string(now->tm_min);
    }
    date +=":";
    if(now->tm_sec <= 9)
    {
        date = date +"0"+std::to_string(now->tm_sec);
    }
    else
    {
        date = date + std::to_string(now->tm_sec);
    }

    return date;



}
std::string CurrentTime::getDateddmmyyyyhhmm()
{
    update();
        std::string date = this->getDateddmmyyyy();
        date += " ";
        if(now->tm_hour <= 9)
        {
            date = date +"0"+std::to_string(now->tm_hour);
        }
        else
        {
            date = date + std::to_string(now->tm_hour);
        }
        date +=":";
        if(now->tm_min <= 9)
        {
            date = date +"0"+std::to_string(now->tm_min);
        }
        else
        {
            date = date + std::to_string(now->tm_min);
        }

        return date;

}
CurrentTime::~CurrentTime()
{
//Void
}
