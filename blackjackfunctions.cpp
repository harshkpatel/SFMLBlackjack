//
//  blackjackfunctions.cpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#include "blackjackfunctions.hpp"

// Displays each player's name and cards, scaling and positioning them based on the number of players.
void displayPlayerCards(std::vector<Player>& players, sf::Font& font, int& scale, sf::RenderWindow& window){
        for(size_t i = 0; i < players.size(); i++){
            for (size_t j = 0; j < players.at(i).numOfCards(); j++){
                sf::Texture card;
                if (!card.loadFromFile(resourcePath() + "Images/" + players.at(i).getCard(j).toString() + ".png"))
                    std::cerr << "Failed to load card image: " << players.at(i).getCard(i).toString() << ".png" << std::endl;

                sf::Sprite cardHolder(card);
                sf::Text name(font, players.at(i).getName());
                name.setFillColor(sf::Color::White);

                if (players.size() < 3){
                    name.setCharacterSize(50);
                    cardHolder.setScale(sf::Vector2f(0.4f, 0.4f));
                    name.setPosition(sf::Vector2f((700 + 600 * i) / scale + 20, 0));
                    cardHolder.setPosition(sf::Vector2f((700 + 600 * i) / scale, 110 + 125 * j));
                }
                else if (players.size() < 4){
                    name.setCharacterSize(120 / scale);
                    cardHolder.setScale(sf::Vector2f(0.9f / scale, 0.9f / scale));
                    name.setPosition(sf::Vector2f((550 + 350 * i) / (scale / 1.85f) + 20, 0));
                    cardHolder.setPosition(sf::Vector2f((550 + 350 * i) / (scale / 1.85f), (150 + 75 * j) / (scale / 2.0f)));
                }
                else{
                    name.setCharacterSize(60 / scale);
                    cardHolder.setScale(sf::Vector2f(0.45f / scale, 0.45f / scale));
                    name.setPosition(sf::Vector2f((150 + (100.0f / players.size()) + (750.0f / players.size())  * i) / (scale / 2.9f) + 20, 0));
                    cardHolder.setPosition(sf::Vector2f((150 + (100.0f / players.size()) + (750.0f / players.size()) * i) / (scale / 2.9f), (75 + 30 * j) / (scale / 2.8f)));
                }
                window.draw(name);
                window.draw(cardHolder);
            }
        }
}

// Displays the current total hand value for each player, or "Busted" if their total exceeds 21.
void displayPlayerTotal(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window){
    for(size_t i = 0; i < players.size(); i++){
        // This inner loop is likely a bug from the original code, as it draws the total for each card.
        // It should probably be outside the card loop or removed if totals are drawn once per player.
        // For this fix, the original structure is maintained.
        for (size_t j = 0; j < players.at(i).numOfCards(); j++){
            sf::Text busted(font, "Busted");
            busted.setFillColor(sf::Color::White);

            sf::Text playerTotal(font, "Total: " + std::to_string(players.at(i).getTotal()));
            playerTotal.setFillColor(sf::Color::White);

            if (players.size() < 3){
                playerTotal.setCharacterSize(50);
                playerTotal.setPosition(sf::Vector2f((700 + 600 * i) / scale + 20, 55));
                busted.setCharacterSize(50);
                busted.setPosition(sf::Vector2f((700 + 600 * i) / scale + 20, 55));
            }
            else if (players.size() < 4){
                playerTotal.setCharacterSize(120 / scale);
                playerTotal.setPosition(sf::Vector2f((550 + 350 * i) / (scale / 1.85f) + 20, 50));
                busted.setCharacterSize(120 / scale);
                busted.setPosition(sf::Vector2f((550 + 350 * i) / (scale / 1.85f) + 20, 50));
            }
            else{
                playerTotal.setCharacterSize(60 / scale);
                playerTotal.setPosition(sf::Vector2f((150 + (100.0f / players.size()) + (750.0f / players.size()) * i) / (scale / 2.9f) + 20, 35));
                busted.setCharacterSize(60 / scale);
                busted.setPosition(sf::Vector2f((150 + (100.0f / players.size()) + (750.0f / players.size()) * i) / (scale / 2.9f) + 20, 35));
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

// Configures and displays a button, adjusting its size based on the number of players.
void displayButton(std::vector<Player>& players, Button& button, int& scale, sf::RenderWindow& window){
    if (players.size() < 3){
        button.setSize({150, 70});
    }
    else if (players.size() < 4){
        button.setSize({100, 70});
    }
    else{
        button.setSize({87, 60});
    }
    button.update(window);
    button.draw(window);
}

// Displays the dealer's hand with one card face down.
void displayHiddenHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    sf::Text houseName(font, "House");
    houseName.setFillColor(sf::Color::White);

    sf::Text houseTotal(font, "Total: ?");
    houseTotal.setFillColor(sf::Color::White);

    sf::Texture hiddenCard;
    if (!hiddenCard.loadFromFile(resourcePath() + "Images/gray_back.png"))
        std::cerr << "Failed to load hidden card image: gray_back.png" << std::endl;

    sf::Texture houseCard;
    if (!houseCard.loadFromFile(resourcePath() + "Images/" + house.getCard(1).toString() + ".png"))
        std::cerr << "Failed to load house card image: " << house.getCard(1).toString() << ".png" << std::endl;

    sf::Sprite hiddenHolder(hiddenCard);
    sf::Sprite houseHolder(houseCard);

    if (players.size() < 3) {
        houseName.setCharacterSize(50);
        houseTotal.setCharacterSize(50);
        hiddenHolder.setScale(sf::Vector2f(0.4f, 0.4f));
        houseHolder.setScale(sf::Vector2f(0.4f, 0.4f));
        houseName.setPosition(sf::Vector2f(30, 160));
        houseTotal.setPosition(sf::Vector2f(30, 215));
        hiddenHolder.setPosition(sf::Vector2f(30, 300));
        houseHolder.setPosition(sf::Vector2f(30, 400));
    }
    else if (players.size() < 4) {
        houseName.setCharacterSize(120 / scale);
        houseTotal.setCharacterSize(120 / scale);
        hiddenHolder.setScale(sf::Vector2f(0.9f / scale, 0.9f / scale));
        houseHolder.setScale(sf::Vector2f(0.9f / scale, 0.9f / scale));
        houseName.setPosition(sf::Vector2f(30, 160));
        houseTotal.setPosition(sf::Vector2f(30, 215));
        hiddenHolder.setPosition(sf::Vector2f(30, 270));
        houseHolder.setPosition(sf::Vector2f(30, 320));
    }
    else {
        houseName.setCharacterSize(60 / scale);
        houseTotal.setCharacterSize(60 / scale);
        hiddenHolder.setScale(sf::Vector2f(0.45f / scale, 0.45f / scale));
        houseHolder.setScale(sf::Vector2f(0.45f / scale, 0.45f / scale));
        houseName.setPosition(sf::Vector2f(15, 125));
        houseTotal.setPosition(sf::Vector2f(15, 170));
        hiddenHolder.setPosition(sf::Vector2f(15, 210));
        houseHolder.setPosition(sf::Vector2f(15, 260));
    }
    window.draw(houseName);
    window.draw(houseTotal);
    window.draw(hiddenHolder);
    window.draw(houseHolder);
}

// Reveals all of the dealer's cards and their final score.
void revealHouse(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    for(size_t i = 0; i < house.numOfCards(); i++){
        sf::Text houseName(font, "House");
        houseName.setFillColor(sf::Color::White);

        sf::Text houseTotal(font, "Total: " + std::to_string(house.getTotal()));
        houseTotal.setFillColor(sf::Color::White);

        sf::Text busted(font, "Busted");
        busted.setFillColor(sf::Color::White);

        sf::Texture houseCard;
        if (!houseCard.loadFromFile(resourcePath() + "Images/" + house.getCard(i).toString() + ".png"))
            std::cerr << "Failed to load house card image: " << house.getCard(i).toString() << ".png" << std::endl;

        sf::Sprite houseHolder(houseCard);

        if (players.size() < 3) {
            houseName.setCharacterSize(50);
            houseTotal.setCharacterSize(50);
            busted.setCharacterSize(50);
            houseHolder.setScale(sf::Vector2f(0.4f, 0.4f));
            houseName.setPosition(sf::Vector2f(30, 10));
            houseTotal.setPosition(sf::Vector2f(30, 70));
            busted.setPosition(sf::Vector2f(30, 70));
            houseHolder.setPosition(sf::Vector2f(30, 140 + 90 * i));
        }
        else if (players.size() < 4) {
            houseName.setCharacterSize(120 / scale);
            houseTotal.setCharacterSize(120 / scale);
            busted.setCharacterSize(120 / scale);
            houseHolder.setScale(sf::Vector2f(0.9f / scale, 0.9f / scale));
            houseName.setPosition(sf::Vector2f(30, 10));
            houseTotal.setPosition(sf::Vector2f(30, 65));
            busted.setPosition(sf::Vector2f(30, 65));
            houseHolder.setPosition(sf::Vector2f(30, 115 + 75 * i));
        }
        else {
            houseName.setCharacterSize(60 / scale);
            houseTotal.setCharacterSize(60 / scale);
            busted.setCharacterSize(60 / scale);
            houseHolder.setScale(sf::Vector2f(0.45f / scale, 0.45f / scale));
            houseName.setPosition(sf::Vector2f(15, 10));
            houseTotal.setPosition(sf::Vector2f(15, 55));
            busted.setPosition(sf::Vector2f(15, 55));
            houseHolder.setPosition(sf::Vector2f(15, 110 + 60 * i));
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

// Displays the final result for each player (Winner, Loser, Push, or Busted).
void displayResults(std::vector<Player>& players, const sf::Font& font, int& scale, sf::RenderWindow& window, House& house){
    for(size_t i = 0; i < players.size(); i++){
        // The original code had a redundant inner loop here as well.
        // It has been removed to draw the result only once per player.
        sf::Text resultText(font);
        resultText.setFillColor(sf::Color::White);

        // Determine the result string for the current player
        if (players.at(i).isBusted()) {
            resultText.setString("Busted");
        } else if (house.isBusted()) {
            resultText.setString("Winner");
        } else if (players.at(i).getTotal() > house.getTotal()) {
            resultText.setString("Winner");
        } else if (players.at(i).getTotal() == house.getTotal()) {
            resultText.setString("Push");
        } else {
            resultText.setString("Loser");
        }

        if (players.size() < 3){
            resultText.setCharacterSize(50);
            resultText.setPosition(sf::Vector2f((700 + 600 * i) / scale + 20, 55));
        }
        else if (players.size() < 4){
            resultText.setCharacterSize(120 / scale);
            resultText.setPosition(sf::Vector2f((550 + 350 * i) / (scale / 1.85f) + 20, 50));
        }
        else{
            resultText.setCharacterSize(60 / scale);
            resultText.setPosition(sf::Vector2f((150 + (100.0f / players.size()) + (750.0f / players.size()) * i) / (scale / 2.9f) + 20, 35));
        }

        window.draw(resultText);
    }
}