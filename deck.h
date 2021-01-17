//Deck Class
//This class is to represent the original deck that distrubutes cards to players and the house
//Harsh Patel

#ifndef DECK_H
#define DECK_H
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "blackjackfunctions.hpp"
#include "button.hpp"
#include "hand.h"
#include "player.h"
#include <stdlib.h>
#include <time.h>

class Deck: public Hand
{
private:
    std::vector<Card> cards;
public:
    /*There is an additional function of clear deck as it represents a different element compared
    to the hands of the user and has a seperate element than the hands of players and house*/
    Deck();
    void populate();
    void shuffle();
    void deal(Hand& playerHand);
    bool drawMore(Genplayer& gp, Button& hit, Button& stand);
    void clearDeck();
};

#endif // DECK_H
