#pragma once
#include "Component.h"

class RectShape : public Component
{
public:
	RectShape(uint32_t id) : Component( id ) { Scene::createdRects[id] = this; };

	virtual ~RectShape();

	bool setTexture(const std::string&);
	void setRGBColor(const sf::Vector3<int>&);
	void rectangleShape(const sf::Vector2<float>&);
	sf::FloatRect getBounds();

	void Draw(sf::RenderWindow&);

private:
	sf::RectangleShape _rectangleShape{};
	sf::Vector3<int> _color{ 0, 0, 0 };
	sf::Texture _tex{};
};

