#include "card.h"

//constructor to set card values
Card::Card(Suit suit, Value value)
{
    this->value = value;
    this->suit = suit;
}

//function to display cards to console using switch case
std::string Card::toString() {
    std::string stringSuit;
    std::string stringValue;

    switch (this->suit) {
    case Suit::DIAMOND:
        stringSuit = "D";
        break;
    case Suit::CLUB:
        stringSuit = "C";
        break;
    case Suit::SPADE:
        stringSuit = "S";
        break;
    case Suit::HEART:
        stringSuit = "H";
        break;
    }

    switch (this->value) {
    case Value::ACE:
        stringValue = "A";
        break;
    case Value::TWO:
        stringValue = "2";
        break;
    case Value::THREE:
        stringValue = "3";
        break;
    case Value::FOUR:
        stringValue = "4";
        break;
    case Value::FIVE:
        stringValue = "5";
        break;
    case Value::SIX:
        stringValue = "6";
        break;
    case Value::SEVEN:
        stringValue = "7";
        break;
    case Value::EIGHT:
        stringValue = "8";
        break;
    case Value::NINE:
        stringValue = "9";
        break;
    case Value::TEN:
        stringValue = "10";
        break;
    case Value::JACK:
        stringValue = "J";
        break;
    case Value::QUEEN:
        stringValue = "Q";
        break;
    case Value::KING:
        stringValue = "K";
        break;
    }

    return stringValue + stringSuit;
}

//return the value of the card
Value Card::getValue() const{
    return this->value;
}
