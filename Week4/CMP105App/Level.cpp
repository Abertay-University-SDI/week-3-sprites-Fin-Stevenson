#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	// initialise game objects
	texture.loadFromFile("gfx/Checkerboard.png");
	texture.setRepeated(true);
	bg.setTexture(&texture);
	bg.setTextureRect(sf::IntRect(-2400, -2400, 2400, 2400));
	bg.setSize(sf::Vector2f(10000.f, 10000.f));
	player = new Player(input, window);
	mCameraFollow = new CameraFollow(window, player);
	point.color = sf::Color::Green;
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
	player->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player->update(dt);
	mCameraFollow->update(dt);
	point.position = mCameraFollow->getCenter();
}

// Render level
void Level::render()
{
	beginDraw();
	window->setView(*mCameraFollow);
	window->draw(bg);
	window->draw(player->getCircle());
	window->draw(*player);
	window->draw(&point, 1, sf::Points);
	endDraw();
}
