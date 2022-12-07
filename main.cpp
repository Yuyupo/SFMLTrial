#include <SFML/Graphics.hpp>
#include <iostream>

#include "Block.h"
#include "GameObject.h"
#include "Scene.h"

uint32_t Scene::_objectCounter = 0;
std::vector<GameObject*> Scene::_createdObjects;
std::vector<uint32_t> Scene::_availableId;

std::vector<Sprite*> Scene::createdSprites;
std::vector<RectShape*> Scene::createdRects;
std::vector<Collider*> Scene::createdColliders;
std::vector<CircleShape*> Scene::createdCircles;

int main()
{
    unsigned int window_height = 600;
    unsigned int window_width = 800;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                            "SFML works!");

    GameObject* player = new GameObject();
    player->addRectComponent();
    RectShape* playerShape = player->getRectComponent();
    playerShape->rectangleShape({ 200, 30 });
    playerShape->setPosition({ 300, 550 });
    playerShape->setRGBColor({0, 0, 0});
    playerShape->setMovable();
    player->addColliderComponent();
    Collider* playerCollider = player->getColliderComponent();
    playerCollider->createColliderWithSize(playerShape->getBounds());

    GameObject* windowObject = new GameObject();
    windowObject->addColliderComponent();
    Collider* windowCollider = windowObject->getColliderComponent();
    windowCollider->createColliderWithSize({ 0.f, 0.f, 800.f, 600.f });

    GameObject* ball = new GameObject();
    ball->addCircleComponent();
    CircleShape* ballShape = ball->getCircleComponent();
    ballShape->circleShape(20.f);
    ballShape->setRGBColor({ 0, 0, 0 });
    ball->addColliderComponent();
    Collider* ballCollider = ball->getColliderComponent();
    ballCollider->createColliderWithSize(ballShape->getBounds());

    std::vector<GameObject*> objects;
    float offset = 0;
    for (int i = 0; i < 8; i++) {
        GameObject* forCollision = new GameObject();
        forCollision->addRectComponent();
        RectShape* collisionShape = forCollision->getRectComponent();
        collisionShape->setTexture("assets/sean-teo-kaae-tileabletextures-wood.jpg");
        collisionShape->rectangleShape({ 100, 45 });
        collisionShape->setPosition({ offset, 30 });
        forCollision->addColliderComponent();
        Collider* collisionCollider = forCollision->getColliderComponent();
        collisionCollider->createColliderWithSize(collisionShape->getBounds());
        collisionCollider->makeDestructible();
        objects.push_back(forCollision);
        offset += 110;
    }

    sf::Clock frameClock;
    // TODO: Hero, mozog, collideol
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(125, 125, 125));
        for (auto* sprite : Scene::createdSprites) {
            if (sprite != nullptr) {
                sprite->Draw(window);
            }
        }

        for (auto* shape : Scene::createdRects) {
            if (shape != nullptr) {
                shape->Draw(window);
            }
        }

        std::vector<Collider*> collided;
        for (auto* collider : Scene::createdColliders) {
            if (collider != nullptr) {
                collider->DrawDebug(window);

                // collider->isColliding();
            }
        }

        for (auto* coll : collided) {
            if (coll->_isDestructible) {
                std::cout << "Deletable object: " << coll->_gameObjectID << std::endl;
                delete Scene::_createdObjects[coll->_gameObjectID];
            }
        }

        for (auto* circle : Scene::createdCircles) {
            if (circle != nullptr) {
               // circle->Draw(window, frameClock.restart().asSeconds());
            }
        }

        window.display();
    }

    // Cleanup
    for (auto* object : Scene::_createdObjects) {
        delete object;
    }
    return 0;
}
