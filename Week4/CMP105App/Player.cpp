#include "Player.h"
#include <iostream>

Player::Player(Input* in, sf::RenderWindow* wndw)
	:GameObject()
{
	setInput(in);
	setWindow(wndw);

	setSize(sf::Vector2f(100, 100));
	setPosition(sf::Vector2f(100, 100));
	mSpeed = sf::Vector2f(0, 0);
}

void Player::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::W))
	{
		mSpeed.y -= maxSpeed;
	}

	if (input->isPressed(sf::Keyboard::S))
	{
		mSpeed.y += maxSpeed;
	}

	if (input->isPressed(sf::Keyboard::A))
	{
		mSpeed.x -= maxSpeed;
	}

	if (input->isPressed(sf::Keyboard::D))
	{
		mSpeed.x += maxSpeed;
	}
}

void Player::update(float dt)
{
	move(mSpeed * dt);
	
	if (fabs(mSpeed.x) > 500.0f)
	{
		mSpeed.x = 500.0f;
	}

	if (fabs(mSpeed.y) > 500.0f)
	{
		mSpeed.y = 500.0f;
	}
}