#include <SFML\Graphics.hpp>
#include "Player.hpp"

Player::Player(){
    playerBody = new sf::RectangleShape(sf::Vector2f(256.0f, 32.0f));
    playerBody->setFillColor(sf::Color::Red);  
    playerBody->setPosition(sf::Vector2f(512.0f, 640.0f));
}

void Player::drawPlayer(sf::RenderWindow* wnd)
{
    wnd->draw(*playerBody);
}

sf::RectangleShape Player::getPlayerBody()
{
    return *playerBody;
}

void Player::movePlayer(float offset, float deltaTime)
{
    playerBody->move(sf::Vector2f(offset*deltaTime, 0.0f));
}

sf::Vector2f Player:: getPlayerPosition(){
    return playerBody->getPosition();
}


    