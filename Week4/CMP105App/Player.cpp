#include "Player.h"
#include <iostream>

Player::Player(Input* in, sf::RenderWindow* wndw)
	:GameObject()
{
	setInput(in);
	setWindow(wndw);

	setSize(sf::Vector2f(100, 100));
	setPosition(sf::Vector2f(100, 100));
	setFillColor(sf::Color::Red);

}

void Player::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::W))
	{
		setVelocity(getVelocity().x, getVelocity().y - maxSpeed);
	}

	if (input->isPressed(sf::Keyboard::S))
	{
		setVelocity(getVelocity().x, getVelocity().y + maxSpeed);
	}

	if (input->isPressed(sf::Keyboard::A))
	{
		setVelocity(getVelocity().x - maxSpeed, getVelocity().y);
	}

	if (input->isPressed(sf::Keyboard::D))
	{
		setVelocity(getVelocity().x + maxSpeed, getVelocity().y);
	}

	if (input->isPressed(sf::Keyboard::K))
	{
		setVelocity(sf::Vector2f(0, 0));
	}
}

void Player::update(float dt)
{
	move(getVelocity() * dt);
	circle.move(getVelocity() * dt);
	if (fabs(getVelocity().x) > 500.0f)
	{
		if (getVelocity().x < 0)
		{
			setVelocity(-500.0f, getVelocity().y);
		}
		else
		{
			setVelocity(500.0f, getVelocity().y);
		}
	}

	if (fabs(getVelocity().y) > 500.0f)
	{
		if (getVelocity().y < 0)
		{
			setVelocity(getVelocity().x, -500.0f);
		}
		else
		{
			setVelocity(getVelocity().x, 500.0f);
		}
	}
}