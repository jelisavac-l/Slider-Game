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

void Coin::moveCoinY(float offset, float deltaTime)
{
    coinBody->move(sf::Vector2f(0.0f, offset*deltaTime));
}

void Coin::moveCoinX(float offset)
{
    coinBody->move(sf::Vector2f(offset, 0.0f));
    if(coinBody->getPosition().x < 0 || coinBody->getPosition().x > 1248)
    {
        coinBody->setPosition(0.0f, 0.0f);
    }
}

void Coin::setXCoordinate(float x)
{
    // Y stays the same, only x changes
    coinBody->setPosition(x, coinBody->getPosition().y);
}

sf::Vector2f Coin::getCoinPosition(){
    return coinBody->getPosition();
}