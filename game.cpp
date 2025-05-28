#include "game.h"
#include <cmath>

//constructor for players in game
Game::Game(std::vector<Player>& players, int& scale){
    this->players = players;
    this->scale = scale;
    playingDeck.populate();
    playingDeck.shuffle();
    for (size_t i = 0; i < this->players.size(); i++){
        playingDeck.deal(this->players.at(i));
        playingDeck.deal(this->players.at(i));
        for (size_t j = 0; j < players.at(i).numOfCards(); j++){
        }
    }
    playingDeck.deal(house);
    playingDeck.deal(house);
    setState(GameState::HITTING);
    currentPlayer = 0;
    counter = 0;
}

//plays a round of Blackjack
void Game::playRound(sf::RenderWindow& window, bool& release, sf::Font& font){
    Button hit("Hit", font, sf::Color::Black, release);
    Button stand("Stand", font, sf::Color::Black, release);
    if (players.size() < 3) {
        hit.setPos({30, 80});
        stand.setPos({190, 80});
    }
    else if (players.size() < 4) {
        hit.setPos({30, 80 });
        stand.setPos({150, 80});
    }
    else {
        hit.setPos({15, 60});
        stand.setPos({107, 60});
    }
    sf::Text currPlayer(font, players.at(currentPlayer).getName() + ":", 40);
    currPlayer.setFillColor(sf::Color::White);
    currPlayer.setPosition(sf::Vector2f(15, 5));
    displayPlayerCards(players, font, scale, window);
    if(getState() == GameState::HITTING){
        displayPlayerTotal(players, font, scale, window);
    if(counter < players.size()){
        window.draw(currPlayer);
        displayHiddenHouse(players, font, scale, window, house);
        displayButton(players, hit, scale, window);
        displayButton(players, stand, scale, window);
        if(!playingDeck.drawMore(players.at(currentPlayer), hit, stand)){
            currentPlayer = (currentPlayer + 1) % players.size();
            counter++;
        }
    }
    else{
        revealHouse(players, font, scale, window, house);
        if(house.isHitting())
            playingDeck.deal(house);
        else
            setState(GameState::END);
        }
    }
    if(getState() == GameState::END){
        revealHouse(players, font, scale, window, house);
        displayResults(players, font, scale, window, house);
    }
}

void Game::setState(const GameState& state){
    this->state = state;
}
GameState Game::getState() const{
    return this->state;
}
void Game::clear(){
    house.clear();
    for(auto& player : players){
        player.clear();
    }
    playingDeck.clear();
}
