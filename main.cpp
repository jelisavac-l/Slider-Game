#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(16.0f);

    //Deltatime
    float deltaTime = 0.0f;
    sf::Clock clock;
    bool isGameActive = true;

    //Player slider thing
    Player player;

    //Player speed
    const float speed = 300.0f;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

        }


        //Player slider movement

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
           player.movePlayer(-1*speed, deltaTime);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
           player.movePlayer(speed, deltaTime);
        }

        window.clear();
        
        player.drawPlayer(&window);

        window.display();
    }

    return 0;
}
