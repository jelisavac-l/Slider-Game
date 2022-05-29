#include <SFML\Graphics.hpp>

#pragma once

class Player{

private:
    sf::RectangleShape *playerBody;
    sf::Texture playerTexture;

public:
    Player();
    void drawPlayer(sf::RenderWindow* wnd);
    void movePlayer(float offset, float deltaTime);
    sf::RectangleShape getPlayerBody();
    sf::Vector2f getPlayerPosition();
};