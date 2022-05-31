#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <cstdlib>
#include "Player.hpp"
#include "Coin.hpp"

//Testing purposes
#include <iostream>

//Definitons of later defined functions
void mainMenu();
void logCmd(const char* str, float val);

int main()
{

    //Display main menu before game starts
    mainMenu();

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Slider Game Project - Luka Jelisavac", sf::Style::Close);

    //Deltatime
    float deltaTime = 0.0f;
    sf::Clock clock;

    // ~S e l f  E x p l a n a t o r y~
    bool isGameActive = true;

    //Player slider thing
    Player player;

    //Player Speed
    float playerSpeed = 640.0f;

    //Coin
    Coin coin;
    //Coin Speed
    float coinSpeed = 160.0f;

    //Background
    sf::Texture background;
    background.loadFromFile("assets/test.jpg");
    
    sf::Sprite backgroundSprite(background);

    //Font and text for showing score
    sf::Font font;
    if(!font.loadFromFile("ProggyClean.ttf"))
    {
        std::cerr << "Font loading error.\n";
        window.close();
    }

    sf::Text text;
    text.setFont(font);
    text.setPosition(8.0f, 8.0f);
    text.setString("Score: 0");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    sf::SoundBuffer blipBuffer;
    if(!blipBuffer.loadFromFile("audio/blip.wav"))
    {
        std::cerr << "Failed loding sound: blip.\n"; 
    }

    sf::Sound blip;
    blip.setBuffer(blipBuffer);

    //Game score
    int score = 0;

    //Game loop
    while (window.isOpen())
    {   
        //Check if game has ended...
        if(isGameActive == false)
        {
            window.close();
        }

        //dTime
        deltaTime = clock.restart().asSeconds();

        //Events and sfml stuff
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

        }

        //Coin falling
        coin.moveCoinY(coinSpeed, deltaTime);

        //Catching mechanism
        if(coin.getCoinBody().getGlobalBounds().intersects(player.getPlayerBody().getGlobalBounds()))
        {
            
            score++;
            blip.play();

            //Random number generator
            int range = 1280 - 0 + 1;
            int num = rand() % range + 0;
            
            //Check if X coordinate is on screen
            if(num < 0) num = 0;
            if(num > 1280) num = 1280 - 32;

            /*
                First we move coin to X = 0 and then we give it random x coordinate
                because .setPosition() is broken somehow...
            */


            //This moves coin to the top

            //This sets coin to X = 0
            coin.moveCoinX(coin.getCoinPosition().x * -1);

            //This will move coin X places to the left
            coin.moveCoinX((float)num);
            
            //And this will move coin to the top
            coin.moveCoinY(-640.0f, 1);

            //Making coin faster each time it is caught
            coinSpeed += 20.0f;
            playerSpeed += 10.0f;

            //Logging and testing purposes
            logCmd("Score", (float)score);
            logCmd("New X pos", (float)num);
            logCmd("coinSpeed", coinSpeed);
            logCmd("playerSpeed", playerSpeed);
            std::cout << "-----------------\n";

            //Displaying score on screen
            std::string scoreChar = "Score: "; 
            text.setString(scoreChar + std::to_string(score));
        }

        //Player slider movement
        //Movement available only if player is inside of screen
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(player.getPlayerPosition().x > 0.0f){
            player.movePlayer(-1*playerSpeed, deltaTime);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(player.getPlayerPosition().x < 1024.0f){
            player.movePlayer(playerSpeed, deltaTime);
            }
        }

        //Checks if game has finished
        if(coin.getCoinBody().getPosition().y > 720)
        {
            isGameActive = false;
        }

        window.clear();
        
        window.draw(backgroundSprite);
        player.drawPlayer(&window);
        coin.drawCoin(&window);
        window.draw(text);

        window.display();
    }

    return 0;
}

//Implementations
void mainMenu()
{
    sf::RenderWindow menu(sf::VideoMode(1280, 720), "", sf::Style::None);

    //dTime for animations
    float deltaTime = 0.0f;
    sf::Clock clock;

    //Loading music 
    sf::Music music;
    if(!music.openFromFile("audio/mainmenu1.ogg")) std::cerr << "Failed loading music...\n";
    music.setVolume(40.0f);
    music.play();

    //Instead of writing text, i could just make an image that already has text
    sf::Texture background;
    background.loadFromFile("assets/test2.jpg");
    
    sf::Sprite backgroundSprite(background);
    backgroundSprite.setOrigin(sf::Vector2f(640.0f, 360.0f));
    backgroundSprite.setPosition(640.0f, 360.0f);
    

    while(menu.isOpen())
    {
        sf::Event evnt;
        while (menu.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::KeyPressed)
                menu.close();
                //music.~Music();
                //background.~Texture();
        }

        deltaTime = clock.restart().asSeconds();

        

        menu.clear();
        menu.draw(backgroundSprite);
        menu.display();
    }

    
}

void logCmd(const char* str, float val)
{
    std::cout << str << ": " << val << std::endl;
}
