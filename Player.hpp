#include <SFML\Graphics.hpp>

#pragma once

class Player{

private:
    sf::RectangleShape *playerBody;

public:
    Player();
    void drawPlayer(sf::RenderWindow* wnd);
    sf::RectangleShape getPlayerBody();
    void movePlayer(float offset, float deltaTime);
};