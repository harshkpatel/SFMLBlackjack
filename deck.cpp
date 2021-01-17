#include "deck.h"

//Constructor of a playing deck for Blackjack
Deck::Deck(){
    this->cards = std::vector<Card>();
}

//fills deck with all 52 cards
void Deck::populate(){
    for(size_t cardSuit = 0; cardSuit < 4; cardSuit++){
        for(size_t cardValue = 0; cardValue < 13; cardValue++){
            this->cards.push_back(Card((Suit)cardSuit, (Value)cardValue));
        }
    }
}

//shuffles deck using rand function
void Deck::shuffle(){
    srand(time(NULL));
    std::vector<Card> tempDeck;
    size_t randomize;
    int originalSize = this->cards.size();

    for(size_t counter = 0; counter < originalSize; counter++){
        randomize = rand() % this->cards.size();
        tempDeck.push_back(this->cards.at(randomize));
        this->cards.erase((this->cards.begin()) + randomize);
    }

    this->cards = tempDeck;
}

//The deck deals a card to the user from the top of the deck
void Deck::deal(Hand& playerHand){
    playerHand.add(this->cards.at(0));
    this->cards.erase(this->cards.begin());
}

//The player continues to draw as they please
bool Deck::drawMore(Genplayer& gp, Button& hit, Button& stand){
    if (hit.isPressed()){
            deal(gp);
    }
    if(gp.isBusted() == true){
        return false;
    }
    if(stand.isPressed()){
        return false;
    }
    return true;
}
//The deck is cleared for a new round
void Deck::clearDeck(){
    this->cards.clear();
}
