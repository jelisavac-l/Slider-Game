#include <SFML/Graphics.hpp>
#include <string.h>
#include <cstdlib>
#include "Player.hpp"
#include "Coin.hpp"

//Testing purposes
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Slider Game Project - Luka Jelisavac", sf::Style::Close);

    //Deltatime
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool isGameActive = true;

    //Player slider thing
    Player player;

    //Player Speed
    const float playerSpeed = 640.0f;

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

    //Coin
    Coin coin;
    
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
            //Random number generator
            int range = 1280 - 0 + 1;
            int num = rand() % range + 0;

            //We want number from -640 to +640 so we shift it 640 places to the left
            num -= 640;
            
            //Check if X coordinate is on screen
            if(num < 0) num = 0;
            if(num > 1280) num = 1280 - 32;

            //End of rng
            coin.moveCoinY(-640.0f, 1);
            coin.moveCoinX(float(num));
            score++;

            //Making coin faster each time it is caught
            coinSpeed += 25.0f;

            //Logging and testing purposes
            std::cout << "Score: " << score << " ";
            std::cout << "Random X Coordinate: " << num << std::endl;
            std::cout << "Coin-Speed: " << coinSpeed << "\n";

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
