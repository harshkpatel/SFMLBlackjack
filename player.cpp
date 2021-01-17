#include "player.h"

//determines if player wants and is able to hit
bool Player::isHitting() const{
    if (isBusted()) {
        return false;
    }
    else
        return true;
}

//functions to announce if player wins, loses or pushes
void Player::win() const{
    std::cout << getName() + " wins" << std::endl;
}
void Player::lose() const{
    std::cout << getName() + " loses" << std::endl;
}
void Player::push() const{
    std::cout << getName() + " pushes" << std::endl;
}
