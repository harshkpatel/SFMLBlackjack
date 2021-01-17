//
//  blackjackfunctions.hpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#ifndef blackjackfunctions_hpp
#define blackjackfunctions_hpp
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "player.h"
#include "button.hpp"
#include "house.h"

void displayPlayerCards(std::vector<Player>& players, sf::Font& font, int& scale, sf::RenderWindow& window);
void displayPlayerTotal(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window);
void displayButton(std::vector<Player>& players, const sf::Font& font, Button& button, int& scale, sf::RenderWindow& window);
void displayHiddenHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house);
void displayCurrentPlayer(Player player, const sf::Font& font, int& scale, sf::RenderWindow& window);
void revealHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house);
void displayResults(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house);


#endif /* blackjackfunctions_hpp */
