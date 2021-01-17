//Player Class
//This class facilitates what happens to a player
//Harsh Patel

#ifndef PLAYER_H
#define PLAYER_H
#include "genplayer.h"
#include <iomanip>


class Player: public Genplayer
{
public:
    virtual bool isHitting() const;
    void win() const;
    void lose() const;
    void push() const;
};
#endif // PLAYER_H
