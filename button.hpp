//
//  button.hpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#ifndef button_hpp
#define button_hpp
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

enum class Btnstates{
    IDLE = 0, HOVER, ACTIVE
};

class Button
{
private:
    Btnstates buttonState;
    bool release;
    sf::RectangleShape button;
    sf::Text text;
public: 
    Button(std::string text, sf::Color color, bool& release);
    
    void setFont(const sf::Font& font);
    void setSize(sf::Vector2f size);
    void setPos(sf::Vector2f pos);
    void setTextColor(sf::Color color);
    void draw(sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    bool isPressed() const;
};

#endif /* button_hpp */
