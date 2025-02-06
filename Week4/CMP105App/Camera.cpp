#include "Camera.h"
#include <cmath>

float lerp(float v0, float v1, float t) {
	return (1 - t) * v0 + t * v1;
}

CameraFollow::CameraFollow(sf::RenderWindow* wndw, GameObject* gameObject)
	:sf::View()
{
	mWindow = wndw;
	mGameObject = gameObject;
	mGameObjCenter = gameObject->getPosition() + (gameObject->getSize() / 2.f);
}

void CameraFollow::update(float dt)
{
	mGameObjCenter = mGameObject->getPosition() + (mGameObject->getSize() / 2.f);

	sf::Vector2f NewPos = sf::Vector2f(lerp(mGameObjCenter.x, getCenter().x, 0.f),lerp(mGameObjCenter.y, getCenter().y, 0.f));
	setCenter(NewPos);
}
