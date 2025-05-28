//
//  button.cpp
//  blackjackSFML
//
//  Created by Harshkumar Patel on 2020-06-02.
//  Copyright © 2020 Harshkumar Patel. All rights reserved.
//

#include "button.hpp"

Button::Button(std::string text, const sf::Font& font, sf::Color color, bool& release) : text(font, text){
    this->release = release;
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    this->button.setFillColor(color);
    this->buttonState = Btnstates::IDLE;
}

void Button::setText(std::string &text) {
    this->text.setString(text);
}

void Button::setFont(const sf::Font& font){
    this->text.setFont(font);
}

void Button::setSize(sf::Vector2f size){
    this->button.setSize(size);
}

void Button::setPos(sf::Vector2f pos){
    button.setPosition(pos);

    int xPos = (pos.x + button.getLocalBounds().position.x) - (text.getLocalBounds().position.x / 2);
    int yPos = (pos.y + button.getLocalBounds().position.y) - (text.getLocalBounds().position.y / 2);
    text.setPosition(sf::Vector2f(xPos, yPos));
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
    int btnXPosWidth = this->button.getPosition().x + this->button.getLocalBounds().position.x;
    int btnYPosHeight = this->button.getPosition().y + this->button.getLocalBounds().position.y;

    if(mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY){
        this->buttonState = Btnstates::HOVER;
        if(release == true){
            this->buttonState = Btnstates::ACTIVE;
        }
    }
}
bool Button::isPressed() const{
    bool temp = this->buttonState == Btnstates::ACTIVE;
    if (temp == true)
        std::cout << "Pressed" << std::endl;
    return(this->buttonState == Btnstates::ACTIVE);
}
