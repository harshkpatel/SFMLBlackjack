//Card Class
//This Class is to represent playing cards in Blackjack
//Harsh Patel

#ifndef CARD_H
#define CARD_H
#include "suit.h"
#include "value.h"
#include <string>

class Card
{
private:
    Suit suit;
    Value value;
public:
    /*card class does not include the isFaceUp() and Flip() as the only time
    that is necessary is with the house so these functions seem unneccesary for the rest of the program.
    There is a toString function to display the elements as it is using enumerations and there needs a function to display it through a string*/
    Card(Suit suit, Value value);
    std::string toString();
    Value getValue() const;
};

#endif // CARD_H
