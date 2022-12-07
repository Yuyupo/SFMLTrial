#pragma once
#include "Component.h"
#include "..\GameObject.h"

class CircleShape : public Component
{
public:
	CircleShape(uint32_t id) : Component({ id }), _gameObjectId(id) { Scene::createdCircles[id] = this; };
	virtual ~CircleShape();

	bool setTexture(std::string file);
	void setRGBColor(sf::Vector3<int> color);
	void setPosition(sf::Vector2<float> position);
	void circleShape(float radius);
	sf::FloatRect getBounds();
	void setMovable();

	void Draw(sf::RenderWindow& window, float dt);

private:
	uint32_t _gameObjectId{ 0 };

	sf::Vector2<float> m_velocity{ 1.2f, 0.75f };
	bool _isMovable{ false };
	sf::CircleShape _circleShape{};
	sf::Vector3<int> _color{ 0, 0, 0 };
	sf::Texture _tex{};
};

