#include "Camera.h"
#include <cmath>
#include <iostream>

float lerp(float v0, float v1, float t) {
	return (1 - t) * v0 + t * v1;
}
float Dist(sf::Vector2f Obj1, sf::Vector2f Obj2)
{
	return sqrt(pow(Obj2.x - Obj1.x, 2) + pow(Obj2.y - Obj1.y, 2));
}

CameraFollow::CameraFollow(sf::RenderWindow* wndw, GameObject* gameObject)
	:sf::View(wndw->getView())
{
	mWindow = wndw;
	mGameObject = gameObject;
	mGameObjCenter = gameObject->getPosition() + (gameObject->getSize() / 2.f);
	setCenter(mGameObjCenter);

	maxDist[0] = sqrt(pow(mGameObject->getSize().x, 2) + pow(mGameObject->getSize().x, 2)) / 2.f;
	maxDist[1] = sqrt(pow(mGameObject->getSize().x, 2) + pow(mGameObject->getSize().x, 2));
}

void CameraFollow::update(float dt)
{
	mGameObjCenter = mGameObject->getPosition() + (mGameObject->getSize() / 2.f);
	sf::Vector2f movement = mGameObjCenter - getCenter();

	if (Dist(mGameObjCenter, getCenter()) > maxDist[0])
	{
		movement *= 1.5f;
	}
	if (Dist(mGameObjCenter, getCenter()) > maxDist[1])
	{
		movement *= 2.f;
	}
	
	move(movement * dt);
	
	
}
