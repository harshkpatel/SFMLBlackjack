#include "hand.h"

//constructor to set up hands of players and house
Hand::Hand()
{
    this->cards = std::vector<Card>();
}

//adds a card to the hand
void Hand::add(Card& card){
    this->cards.push_back(card);
}

//gets the total value of a player's hand
int Hand::getTotal() const{
    int totalValue = 0;
    int aces = 0;

    for (auto& card : cards){
        switch(card.getValue()){
        case Value::ACE:
            aces++;
            break;
        case Value::TWO:
            totalValue += 2;
            break;
        case Value::THREE:
            totalValue += 3;
            break;
        case Value::FOUR:
            totalValue += 4;
            break;
        case Value::FIVE:
            totalValue += 5;
            break;
        case Value::SIX:
            totalValue += 6;
            break;
        case Value::SEVEN:
            totalValue += 7;
            break;
        case Value::EIGHT:
            totalValue += 8;
            break;
        case Value::NINE:
            totalValue += 9;
            break;
        case Value::TEN:
            totalValue += 10;
            break;
        case Value::JACK:
            totalValue += 10;
            break;
        case Value::QUEEN:
            totalValue += 10;
            break;
        case Value::KING:
            totalValue += 10;
            break;
        }
    }

    for(int i = 0; i < aces; i++){
        if(totalValue > 10)
            totalValue++;
        else
            totalValue += 11;
    }

    return totalValue;
}

//clears hand
void Hand::clear(){
    cards.clear();
}

size_t Hand::numOfCards() const{
    return this->cards.size();
}

//displays contents of hand
std::string Hand::toString(){
    std::string unShuffList = "";
    for (auto& card : cards){
        unShuffList += card.toString() + "\t";
    }
    return unShuffList;
}

//shows a specific card
Card Hand::getCard(size_t index){
    return this->cards.at(index);
}
void Hand::addSprite(sf::Sprite& cardSprite){
    this->cardSprites.push_back(cardSprite);
}
sf::Sprite Hand::getSprite(size_t index){
    return this->cardSprites.at(index);
}
