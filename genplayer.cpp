#include "genplayer.h"

//constructor for names of players
Genplayer::Genplayer(){
    this->player = std::string();
}

//determines if the player is busted
bool Genplayer::isBusted() const{
    if(getTotal() <= 21)
        return false;
    else
        return true;
}

//gets name of certian player
std::string Genplayer::getName() const{
    return player;
}

//operator overloading to accept names from user
std::istream& operator>>(std::istream& input, Genplayer& gp){
    input >> gp.player;
    return input;
}
