//Generic Player Class
//Abstract Class to map out some features for the house and players
//Harsh Patel

#ifndef GENPLAYER_H
#define GENPLAYER_H
#include "hand.h"
#include <iostream>


class Genplayer: public Hand
{
private:
    std::string player;
public:
    //There is an operator overload to get input from user for player names
    //There is a getName function to display the names of the different players
    Genplayer();
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    friend std::istream& operator>>(std::istream& input, Genplayer& gp);
    std::string getName() const;
};
std::istream& operator>>(std::istream& input, Genplayer& gp);
#endif // GENPLAYER_H
