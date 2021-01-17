//Hand class
//This class keeps track of the hands of players and the house
//Harsh Patel

#ifndef HAND_H
#define HAND_H
#include "card.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <vector>


class Hand
{
private:
    std::vector<Card> cards;
    std::vector<sf::Sprite> cardSprites;
public:
    //there is a toString function to display the hand of the players and house
    //there is a getCard function to specifically show a certian card in the users hand
    Hand();
    void add(Card& card);
    int getTotal() const;
    void clear();
    size_t numOfCards() const;
    std::string toString();
    Card getCard(size_t index);
    void addSprite(sf::Sprite& cardSprite);
    sf::Sprite getSprite(size_t index);
};

#endif // HAND_H
