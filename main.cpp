
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include "game.h"
using namespace std;

int main()
{
    bool release = false;
    int playerCount, scale;
    Player tempPlayer;
    vector<Player> players;
    char playAgain;
    cout << "Hello, Welcome to Blackjack!" << endl;

    //select player count
    cout << "Select how many players you want (1-7): ";
    cin >> setw(1) >> playerCount;

    //data sanitation
    while(cin.good() == false || playerCount < 1 || playerCount > 7){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid Input, please enter between 1-7 players: ";
        cin >> setw(1) >> playerCount;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    //user gives each player names
    for(int i = 1; i < playerCount + 1; i++){
        cout << "Please enter name for player " + to_string(i) + ": ";
        cin >> setw(6) >> tempPlayer;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        players.push_back(tempPlayer);
    }
    cout << endl;
    sf::RenderWindow window;
    if (playerCount < 4){
        scale = playerCount;
        window.create(sf::VideoMode(1000 , 800), "Blackjack");
        
    }
    else if (playerCount < 6){
        scale = playerCount / 2;
        window.create(sf::VideoMode(700 + (300 * scale), 1100 / scale), "Blackjack");
    }
    else{
        scale = playerCount / 3;
        window.create(sf::VideoMode(750 + (300 * scale), 1200 / scale), "Blackjack");
    }
    window.setKeyRepeatEnabled(false);
    
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "Images/blackjackLogo.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Game blackjack(players, scale);
    
    sf::Texture background;
    if (!background.loadFromFile(resourcePath() + "Images/background.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite bg(background);
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "Images/OpenSans-Regular.ttf"))
        return EXIT_FAILURE;
    sf::RectangleShape rectangle;
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    sf::Text playMore;
    playMore.setFont(font);
    playMore.setString("Play Again?");
    playMore.setFillColor(sf::Color::Black);
    while (window.isOpen()){
        sf::Event event;
        release = false;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::MouseButtonPressed)
                release = true;
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        blackjack.playRound(window, release, font);
        if(blackjack.getState() == GameState::END){
            Button yes("Yes", sf::Color::Black, release);
            Button no("No", sf::Color::Black, release);
            if (players.size() < 3) {
                yes.setPos({320, 300});
                no.setPos({480, 300});
                rectangle.setSize(sf::Vector2f(400, 300));
                rectangle.setPosition(285, 150);
                playMore.setCharacterSize(40);
                playMore.setPosition(360, 180);
            }
            else if (players.size() < 4) {
                yes.setPos({350, 450});
                no.setPos({470, 450});
                rectangle.setSize(sf::Vector2f(400, 300));
                rectangle.setPosition(300, 300);
                playMore.setCharacterSize(40);
                playMore.setPosition(360, 320);
            }
            else {
                yes.setPos({650, 330});
                no.setPos({742, 330});
                rectangle.setSize(sf::Vector2f(300, 250));
                rectangle.setPosition(600, 200);
                playMore.setCharacterSize(40);
                playMore.setPosition(650, 240);
            }
            window.draw(rectangle);
            window.draw(playMore);
            displayButton(players, font, yes, scale, window);
            displayButton(players, font, no, scale, window);
            if(yes.isPressed()){
                blackjack.clear();
                Game tempBlackjack(players, scale);
                blackjack = tempBlackjack;
            }
            else if(no.isPressed())
                window.close();
        }
        window.display();
    }
    return 0;
}
