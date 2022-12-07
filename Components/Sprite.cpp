#include "Sprite.h"

Sprite::~Sprite() {
	Scene::createdSprites[_gameObjectId] = nullptr;
	delete Scene::createdSprites[_gameObjectId];
}

bool Sprite::setTexture(std::string file) {
	if (!_tex.loadFromFile(file)) {
		std::cerr << "Could not load file: " << file << std::endl;
		return false;
	}
	_sprite.setTexture(_tex);
	return true;
}

void Sprite::setRGBColor(sf::Vector3<int> color) {
	_color = color;
	_sprite.setColor(sf::Color(color.x, color.y, color.z));
}

void Sprite::setScale(sf::Vector2<float> scale) {
	_scale = scale;
	_sprite.setScale(scale.x, scale.y);
}

void Sprite::setPosition(sf::Vector2<int> position) {
	_sprite.setPosition(position.x, position.y);
}

sf::FloatRect Sprite::getBounds() {
	sf::FloatRect rectangleRect = _sprite.getLocalBounds();
	return sf::FloatRect(_pos.x, _pos.y, rectangleRect.width * _scale.x, rectangleRect.height * _scale.y);

}

void Sprite::Draw(sf::RenderWindow& window) {
	window.draw(_sprite);
}
