#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	mView = window->getView();
	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	bg.setTexture(&texture);
	bg.setSize(sf::Vector2f(1100, 1100));

	player = new Player(input, window);
	mCameraFollow = new CameraFollow(window, player);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	if (input->isPressed(sf::Keyboard::F))
	{
		std::cout << "Camera Shake  " << view << std::endl;
		if (view)
		{
			view = false;
		}
		else
		{
			view = true;
		}
	}
	player->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player->update(dt);
	mView.move((player->getPosition() + (player->getSize() / 2.f)) * dt);
	mCameraFollow->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	if (view)
	{
		window->setView(*mCameraFollow);
	}
	else
	{
		window->setView(mView);
	}
	window->draw(bg);
	window->draw(*player);
	endDraw();
}
