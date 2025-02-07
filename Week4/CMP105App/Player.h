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

    sf::CircleShape getCircle() { return circle; }
private:
    float maxSpeed = 50.0f;
    sf::CircleShape circle;
};

