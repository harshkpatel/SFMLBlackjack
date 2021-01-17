//
//  blackjackfunctions.cpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#include "blackjackfunctions.hpp"
void displayPlayerCards(std::vector<Player>& players, sf::Font& font, int& scale, sf::RenderWindow& window){
        for(size_t i = 0; i < players.size(); i++){
            for (size_t j = 0; j < players.at(i).numOfCards(); j++){
                sf::Texture card;
                if (!card.loadFromFile(resourcePath() + "Images/" + players.at(i).getCard(j).toString() + ".png"))
                return EXIT_FAILURE;
                sf::Sprite cardHolder(card);
                sf::Text name;
                name.setFont(font);
                name.setString(players.at(i).getName());
                name.setFillColor(sf::Color::White);
                if (players.size() < 3){
                    name.setCharacterSize(50);
                    cardHolder.scale(0.4, 0.4);
                    name.setPosition((700 + 600 * i) / scale + 20, 0);
                    cardHolder.setPosition((700 + 600 * i) / scale, (110 + 125 * j));
                }
                else if (players.size() < 4){
                    name.setCharacterSize(120/scale);
                    cardHolder.scale( 0.9 / scale, 0.9 / scale);
                    name.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 0);
                    cardHolder.setPosition((550 + 350 * i) / (scale / 1.85), (150 + 75 * j) / (scale / 2));
                }
                else{
                    name.setCharacterSize(60/scale);
                    cardHolder.scale( 0.45 / scale, 0.45 / scale);
                    name.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 0);
                    cardHolder.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9), (75 + 30 * j) / (scale / 2.8));
                }
                window.draw(name);
                window.draw(cardHolder);
            }
        }
}
void displayPlayerTotal(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window){
    for(size_t i = 0; i < players.size(); i++){
        for (size_t j = 0; j < players.at(i).numOfCards(); j++){
            sf::Text busted;
            busted.setFont(font);
            busted.setString("Busted");
            busted.setFillColor(sf::Color::White);
            sf::Text playerTotal;
            playerTotal.setFont(font);
            playerTotal.setString("Total: " + std::to_string(players.at(i).getTotal()));
            playerTotal.setFillColor(sf::Color::White);
            if (players.size() < 3){
                playerTotal.setCharacterSize(50);
                playerTotal.setPosition((700 + 600 * i) / scale + 20, 55);
                busted.setCharacterSize(50);
                busted.setPosition((700 + 600 * i) / scale + 20, 55);
            }
            else if (players.size() < 4){
                playerTotal.setCharacterSize(120/scale);
                playerTotal.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
                busted.setCharacterSize(120/scale);
                busted.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
            }
            else{
                playerTotal.setCharacterSize(60/scale);
                playerTotal.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
                busted.setCharacterSize(60/scale);
                busted.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
            }
            if(players.at(i).isBusted()){
                window.draw(busted);
            }
            else{
                window.draw(playerTotal);
            }
        }
    }
}
void displayButton(std::vector<Player>& players, const sf::Font& font, Button& button, int& scale, sf::RenderWindow& window){
            if (players.size() < 3){
                button.setFont(font);
                button.setSize({150, 70});
                button.update(window);
            }
            else if (players.size() < 4){
                button.setFont(font);
                button.setSize({100, 70});
                button.update(window);
            }
            else{
                button.setFont(font);
                button.setSize({87, 60});
                button.update(window);
            }
            button.draw(window);
}
void displayHiddenHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    sf::Text houseName;
    sf::Text houseTotal;
    sf::Texture hiddenCard;
    if (!hiddenCard.loadFromFile(resourcePath() + "Images/gray_back.png"))
        return EXIT_FAILURE;
    sf::Texture houseCard;
    if (!houseCard.loadFromFile(resourcePath() + "Images/" + house.getCard(1).toString() + ".png"))
        return EXIT_FAILURE;
    houseName.setFont(font);
    houseName.setString("House");
    houseName.setFillColor(sf::Color::White);
    houseTotal.setFont(font);
    houseTotal.setString("Total: ?");
    houseTotal.setFillColor(sf::Color::White);
    sf::Sprite hiddenHolder(hiddenCard);
    sf::Sprite houseHolder(houseCard);
    if (players.size() < 3) {
        houseName.setCharacterSize(50);
        houseTotal.setCharacterSize(50);
        hiddenHolder.scale(0.4, 0.4);
        houseHolder.scale(0.4, 0.4);
        houseName.setPosition(30, 160);
        houseTotal.setPosition(30, 215);
        hiddenHolder.setPosition(30, 300);
        houseHolder.setPosition(30, 400);
    }
    else if (players.size() < 4) {
        houseName.setCharacterSize(120 / scale);
        houseTotal.setCharacterSize(120 / scale);
        hiddenHolder.scale(0.9 / scale, 0.9 / scale);
        houseHolder.scale(0.9 / scale, 0.9 / scale);
        houseName.setPosition(30, 160);
        houseTotal.setPosition(30, 215);
        hiddenHolder.setPosition(30, 270);
        houseHolder.setPosition(30, 320);
    }
    else {
        houseName.setCharacterSize(60 / scale);
        houseTotal.setCharacterSize(60 / scale);
        hiddenHolder.scale(0.45 / scale, 0.45 / scale);
        houseHolder.scale(0.45 / scale, 0.45 / scale);
        houseName.setPosition(15, 125);
        houseTotal.setPosition(15, 170);
        hiddenHolder.setPosition(15, 210);
        houseHolder.setPosition(15, 260);
    }
    window.draw(houseName);
    window.draw(houseTotal);
    window.draw(hiddenHolder);
    window.draw(houseHolder);
}
void displayCurrentPlayer(Player player, const sf::Font& font, int& scale, sf::RenderWindow& window){
    sf::Text currentPlayer;
    currentPlayer.setFont(font);
    currentPlayer.setString(player.getName());
    currentPlayer.setFillColor(sf::Color::White);
}
void revealHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    for(size_t i = 0; i < house.numOfCards(); i++){
        sf::Text houseName;
        sf::Text houseTotal;
        sf::Text busted;
        sf::Texture houseCard;
        if (!houseCard.loadFromFile(resourcePath() + "Images/" + house.getCard(i).toString() + ".png"))
            return EXIT_FAILURE;
        houseName.setFont(font);
        houseName.setString("House");
        houseName.setFillColor(sf::Color::White);
        houseTotal.setFont(font);
        houseTotal.setString("Total: " + std::to_string(house.getTotal()));
        houseTotal.setFillColor(sf::Color::White);
        busted.setFont(font);
        busted.setString("Busted");
        busted.setFillColor(sf::Color::White);
        sf::Sprite houseHolder(houseCard);
        if (players.size() < 3) {
            houseName.setCharacterSize(50);
            houseTotal.setCharacterSize(50);
            busted.setCharacterSize(50);
            houseHolder.scale(0.4, 0.4);
            houseName.setPosition(30, 10);
            houseTotal.setPosition(30, 70);
            busted.setPosition(30, 70);
            houseHolder.setPosition(30, 140 + 90 * i);
        }
        else if (players.size() < 4) {
            houseName.setCharacterSize(120 / scale);
            houseTotal.setCharacterSize(120 / scale);
            busted.setCharacterSize(120 / scale);
            houseHolder.scale(0.9 / scale, 0.9 / scale);
            houseName.setPosition(30, 10);
            houseTotal.setPosition(30, 65);
            busted.setPosition(30, 65);
            houseHolder.setPosition(30, 115 + 75 * i);
        }
        else {
            houseName.setCharacterSize(60 / scale);
            houseTotal.setCharacterSize(60 / scale);
            busted.setCharacterSize(60 / scale);
            houseHolder.scale(0.45 / scale, 0.45 / scale);
            houseName.setPosition(15, 10);
            houseTotal.setPosition(15, 55);
            busted.setPosition(15, 55);
            houseHolder.setPosition(15, 110 + 60 * i);
        }
        if(house.isBusted()){
            window.draw(busted);
        }
        else{
            window.draw(houseTotal);
        }
        window.draw(houseName);
        window.draw(houseHolder);
    }
}
void displayResults(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    for(size_t i = 0; i < players.size(); i++){
        for (size_t j = 0; j < players.at(i).numOfCards(); j++){
            sf::Text busted;
            busted.setFont(font);
            busted.setString("Busted");
            busted.setFillColor(sf::Color::White);
            sf::Text winner;
            winner.setFont(font);
            winner.setString("Winner");
            winner.setFillColor(sf::Color::White);
            sf::Text push;
            push.setFont(font);
            push.setString("Push");
            push.setFillColor(sf::Color::White);
            sf::Text loser;
            loser.setFont(font);
            loser.setString("Loser");
            loser.setFillColor(sf::Color::White);
            if (players.size() < 3){
                busted.setCharacterSize(50);
                busted.setPosition((700 + 600 * i) / scale + 20, 55);
                winner.setCharacterSize(50);
                winner.setPosition((700 + 600 * i) / scale + 20, 55);
                push.setCharacterSize(50);
                push.setPosition((700 + 600 * i) / scale + 20, 55);
                loser.setCharacterSize(50);
                loser.setPosition((700 + 600 * i) / scale + 20, 55);
            }
            else if (players.size() < 4){
                busted.setCharacterSize(120/scale);
                busted.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
                winner.setCharacterSize(120/scale);
                winner.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
                push.setCharacterSize(120/scale);
                push.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
                loser.setCharacterSize(120/scale);
                loser.setPosition((550 + 350 * i) / (scale / 1.85) + 20, 50);
            }
            else{
                busted.setCharacterSize(60/scale);
                busted.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
                winner.setCharacterSize(60/scale);
                winner.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
                push.setCharacterSize(60/scale);
                push.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
                loser.setCharacterSize(60/scale);
                loser.setPosition((150 + (100 / players.size()) + (750 / players.size())  * i) / (scale / 2.9) + 20, 35);
            }
            if(house.isBusted()){
                if (!players.at(i).isBusted()){
                    window.draw(winner);
                }
                else{
                    window.draw(busted);
                }
            }
            else{
                if(players.at(i).isBusted()){
                    window.draw(busted);
                }
                else if(!players.at(i).isBusted() && players.at(i).getTotal() > house.getTotal()){
                    window.draw(winner);
                }
                else if(!players.at(i).isBusted() && players.at(i).getTotal() == house.getTotal()){
                    window.draw(push);
                }
                else{
                    window.draw(loser);
                }
            }
        }
    }
}

