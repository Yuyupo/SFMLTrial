#pragma once
#include "Component.h"

class Physics : public Component
{
public:
	Physics(uint32_t id) : Component( id ){ Scene::createdPhysics[id] = this; };

	virtual ~Physics();

    void setSpeed(const sf::Vector2<float>&);

    // Getter mindig konst
    sf::Vector2<float> getSpeed() const { return _speed; }

    void update();

private:
    sf::Vector2<float> _speed{};
};
