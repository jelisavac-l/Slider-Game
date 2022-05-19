#include <SFML/Graphics.hpp>
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
        coin.moveCoin(coinSpeed, deltaTime);

        //Catching mechanism
        if(coin.getCoinBody().getGlobalBounds().intersects(player.getPlayerBody().getGlobalBounds()))
        {
            coin.moveCoin(-640.0f, 1.0f);
            score++;
            std::cout << "Score: " << score << " ";

            //Making coin faster each time it is caught
            coinSpeed += 50.0f;

            std::cout << "Coin-Speed: " << coinSpeed << "\n";
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

        window.clear();

        window.draw(backgroundSprite);
        player.drawPlayer(&window);
        coin.drawCoin(&window);
        
        window.display();
    }

    return 0;
}
