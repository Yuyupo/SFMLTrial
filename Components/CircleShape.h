#pragma once
#include "Component.h"

class CircleShape : public Component
{
public:
	CircleShape(uint32_t id) : Component( id ) { Scene::createdCircles[id] = this; };
	virtual ~CircleShape();

	bool setTexture(const std::string&);
	void setRGBColor(const sf::Vector3<int>&);
	void circleShape(float);
	sf::FloatRect getBounds();

	void Draw(sf::RenderWindow&);

private:
	sf::CircleShape _circleShape{};
	sf::Vector3<int> _color{ 0, 0, 0 };
	sf::Texture _tex{};
};

