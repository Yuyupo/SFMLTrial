#include "Sprite.h"

Sprite::~Sprite() {
	Scene::createdSprites[gameObjectId] = nullptr;
}

bool Sprite::setTexture(const std::string& file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_sprite.setTexture(_tex);
	return true;
}

void Sprite::setRGBColor(const sf::Vector3<int>& color) {
	_color = color;
	_sprite.setColor(sf::Color(color.x, color.y, color.z));
}

void Sprite::setScale(const sf::Vector2<float>& scale) {
	_scale = scale;
	_sprite.setScale(scale.x, scale.y);
}

sf::FloatRect Sprite::getBounds() {
	sf::FloatRect rectangleRect = _sprite.getLocalBounds();
	return sf::FloatRect(getPosition().x, getPosition().y,
						 rectangleRect.width * _scale.x, rectangleRect.height * _scale.y);
}

void Sprite::Draw(sf::RenderWindow& window) {
	_sprite.setPosition(getPosition());
	window.draw(_sprite);
}
