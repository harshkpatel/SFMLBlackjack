//Game Class
//This class faciliates/runs Blackjack
//Harsh Patel

#ifndef GAME_H
#define GAME_H
#include "button.hpp"
#include "house.h"
#include "deck.h"
#include "gamestate.h"

class Game
{
private:
    std::vector<Player> players;
    GameState state;
    int scale;
    House house;
    Deck playingDeck;
    size_t currentPlayer;
    int counter;
public:
    Game(std::vector<Player>& players, int& scale);
    void playRound(sf::RenderWindow& window, bool& release, sf::Font& font);
    void setState(const GameState& state);
    GameState getState() const;
    void clear();
};

#endif // GAME_H
