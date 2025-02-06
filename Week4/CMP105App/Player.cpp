#include "Player.h"
#include <iostream>

Player::Player(Input* in, sf::RenderWindow* wndw)
	:GameObject()
{
	setInput(in);
	setWindow(wndw);

	setSize(sf::Vector2f(100, 100));
	setPosition(sf::Vector2f(100, 100));
}

void Player::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::W))
	{
		mSpeed.y -= 50.0f;
	}

	if (input->isPressed(sf::Keyboard::S))
	{
		mSpeed.y += 50.0f;
	}

	if (input->isPressed(sf::Keyboard::A))
	{
		mSpeed.x -= 50.0f;
	}

	if (input->isPressed(sf::Keyboard::D))
	{
		mSpeed.x += 50.0f;
	}
}

void Player::update(float dt)
{
	move(mSpeed * dt);
}