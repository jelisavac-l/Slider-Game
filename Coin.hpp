#include <SFML\Graphics.hpp>

#pragma once

class Coin{

private:
    sf::RectangleShape *coinBody;

public:
    Coin();
    void drawCoin(sf::RenderWindow* wnd);
    void moveCoinY(float offset, float deltaTime);
    void moveCoinX(float offset);
    void setXCoordinate(float x);
    sf::RectangleShape getCoinBody();
    sf::Vector2f getCoinPosition();
};