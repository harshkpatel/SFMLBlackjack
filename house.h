//House Class
//This class represents the house, what the players go against to win
//Harsh Patel

#ifndef HOUSE_H
#define HOUSE_H
#include "genplayer.h"


class House: public Genplayer
{
public:
    virtual bool isHitting() const;
    void flipFirstCard();
};

#endif // HOUSE_H
