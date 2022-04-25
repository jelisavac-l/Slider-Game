#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Slider Game Project - Luka Jelisavac", sf::Style::Close);

    //Deltatime
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool isGameActive = true;

    //Player slider thing
    Player player;

    //Player speed
    const float speed = 640.0f;

    //Background
    sf::Texture background;
    background.loadFromFile("assets/test.jpg");
    
    sf::Sprite backgroundSprite(background);
    
    //Game loop
    while (window.isOpen())
    {
        //dTime
        deltaTime = clock.restart().asSeconds();

        //Events and sfml stuff
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

        }


        //Player slider movement
        //Movement available only if player is inside of screen
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(player.getPlayerPosition().x > 0.0f){
            player.movePlayer(-1*speed, deltaTime);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(player.getPlayerPosition().x < 1024.0f){
            player.movePlayer(speed, deltaTime);
            }
        }

        window.clear();

        window.draw(backgroundSprite);
        player.drawPlayer(&window);
        
        window.display();
    }

    return 0;
}
