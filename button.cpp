//
//  button.cpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#include "button.hpp"

Button::Button(std::string text, sf::Color color, bool& release){
    this->release = release;
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    this->button.setFillColor(color);
    this->buttonState = Btnstates::IDLE;
}
void Button::setFont(const sf::Font& font){
    this->text.setFont(font);
}

void Button::setSize(sf::Vector2f size){
    this->button.setSize(size);
}

void Button::setPos(sf::Vector2f pos){
    button.setPosition(pos);
    
    int xPos = (pos.x + button.getLocalBounds().width) - (text.getLocalBounds().width / 2);
    int yPos = (pos.y + button.getLocalBounds().height) - (text.getLocalBounds().height / 2);
    text.setPosition(xPos, yPos);
}

void Button::setTextColor(sf::Color color){
    this->text.setFillColor(color);
}

void Button::draw(sf::RenderWindow& window){
    window.draw(this->button);
    window.draw(this->text);
}

void Button::update(const sf::RenderWindow& window){
    this->buttonState = Btnstates::IDLE;
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;
    int btnPosX = this->button.getPosition().x;
    int btnPosY = this->button.getPosition().y;
    int btnXPosWidth = this->button.getPosition().x + this->button.getLocalBounds().width;
    int btnYPosHeight = this->button.getPosition().y + this->button.getLocalBounds().height;
    
    if(mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY){
        this->buttonState = Btnstates::HOVER;
        if(release == true){
            this->buttonState = Btnstates::ACTIVE;
        }
    }
}
bool Button::isPressed() const{
    return(this->buttonState == Btnstates::ACTIVE);
}
