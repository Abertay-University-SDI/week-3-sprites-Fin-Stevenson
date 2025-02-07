#pragma once
#include "SFML/Graphics.hpp"
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class CameraFollow : public sf::View
{
public:
	CameraFollow(sf::RenderWindow* wndw, GameObject* GameObject);
	void update(float dt);
private:
	sf::RenderWindow* mWindow;
	GameObject* mGameObject;
	sf::Vector2f mGameObjCenter;

	float maxDist[2];
};

