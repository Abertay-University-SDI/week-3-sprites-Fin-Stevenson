#include "Camera.h"

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
	move(mGameObjCenter);
}
