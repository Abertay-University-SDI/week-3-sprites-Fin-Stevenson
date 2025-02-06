#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"
class Player :
    public GameObject
{
public:
    Player(Input*, sf::RenderWindow*);

    void handleInput(float dt) override;
    void update(float dt) override;

private:
    sf::Vector2f mSpeed = sf::Vector2f(0,0);
};

