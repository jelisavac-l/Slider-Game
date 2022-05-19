#include <SFML\Graphics.hpp>
#include "Coin.hpp"

Coin::Coin(){
    coinBody = new sf::RectangleShape(sf::Vector2f(32.0f, 32.0f));
    coinBody->setFillColor(sf::Color::Blue);
    coinBody->setPosition(sf::Vector2f(640.0f, 0.0f));
}

void Coin::drawCoin(sf::RenderWindow *wnd)
{
    wnd->draw(*coinBody);
}

sf::RectangleShape Coin::getCoinBody()
{
    return *coinBody;
}

void Coin::moveCoin(float offset, float deltaTime)
{
    coinBody->move(sf::Vector2f(0.0f, offset*deltaTime));
}

sf::Vector2f Coin::getCoinPosition(){
    return coinBody->getPosition();
}