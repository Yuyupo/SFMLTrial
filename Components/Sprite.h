#pragma once
#include "Component.h"
#include "..\GameObject.h"

class Sprite : public Component
{
public:
	Sprite(uint32_t id) : Component({id}), _gameObjectId(id), _pos(0, 0) { Scene::createdSprites[id] = this; };

	virtual ~Sprite();

	bool setTexture(std::string file);
	void setRGBColor(sf::Vector3<int> color);
	void setScale(sf::Vector2<float> scale);
	void setPosition(sf::Vector2<int> position);
	sf::FloatRect getBounds();

	void Draw(sf::RenderWindow& window);
private:
	uint32_t _gameObjectId{ 0 };

	sf::Vector3<int> _color{0, 0, 0};
	sf::Texture _tex{};
	sf::Sprite _sprite{};
	sf::Vector2<float> _scale{0.f, 0.f};
	sf::Vector2<int> _pos{0, 0};
};

