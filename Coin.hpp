#include <SFML\Graphics.hpp>

#pragma once

class Coin{

private:
    sf::RectangleShape *coinBody;

public:
    Coin();
    void drawCoin(sf::RenderWindow* wnd);
    void moveCoin(float offset, float deltaTime);
    sf::RectangleShape getCoinBody();
    sf::Vector2f getCoinPosition();
};