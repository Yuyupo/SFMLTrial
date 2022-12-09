#pragma once
#include "Component.h"

class Sprite : public Component
{
public:
	Sprite(uint32_t id) : Component( id ) { Scene::createdSprites[id] = this; };

	virtual ~Sprite();

	// TODO: being able to add sprite sheet

	bool setTexture(const std::string&);
	void setRGBColor(const sf::Vector3<int>&);
	void setScale(const sf::Vector2<float>&);
	// Get the bounding rectangle of the shape.
	// Can be used for collider creation.
	sf::FloatRect getBounds();

	void Draw(sf::RenderWindow&);
private:
	sf::Vector3<int> _color{0, 0, 0};
	sf::Texture _tex{};
	sf::Sprite _sprite{};
	sf::Vector2<float> _scale{0.f, 0.f};
};

