#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

#include "Block.h"
#include "GameObject.h"
#include "Scene.h"
#include "Components/Sprite.h"
#include "Components/RectShape.h"
#include "Components/Collider.h"
#include "Components/CircleShape.h"
#include "Components/Physics.h"

uint32_t Scene::_objectCounter = 0;
std::vector<GameObject*> Scene::_createdObjects;
std::vector<uint32_t> Scene::_availableId;

std::vector<Sprite*> Scene::createdSprites;
std::vector<RectShape*> Scene::createdRects;
std::vector<Collider*> Scene::createdColliders;
std::vector<CircleShape*> Scene::createdCircles;
std::vector<Physics*> Scene::createdPhysics;

int main()
{
    unsigned int window_height = 600;
    unsigned int window_width = 800;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                            "SFML works!");

    std::vector<GameObject*> objects;
    float offset = 0;
    sf::Vector2<float> blocksSize = { 100, 45 };
    for (int i = 0; i < 8; i++) {
        GameObject* forCollision = new GameObject();
        forCollision->setPosition({ offset, 30.f });
        forCollision->addRectComponent();
        RectShape* collisionShape = forCollision->getRectComponent();
        collisionShape->setTexture("assets/sean-teo-kaae-tileabletextures-wood.jpg");
        collisionShape->rectangleShape(blocksSize);
        forCollision->addColliderComponent();
        Collider* collisionCollider = forCollision->getColliderComponent();
        collisionCollider->createColliderWithSize(blocksSize);
        collisionCollider->makeDestructible();
        objects.push_back(forCollision);
        offset += 110;
    }

    GameObject* player = new GameObject();
    player->setPosition({ 300, 550 });
    player->addRectComponent();
    RectShape* playerShape = player->getRectComponent();
    playerShape->rectangleShape({ 200, 30 });
    playerShape->setRGBColor({ 0, 0, 0 });
    player->addColliderComponent();
    Collider* playerCollider = player->getColliderComponent();
    playerCollider->createColliderWithSize({ 200, 30 });

    objects.push_back(player);

    GameObject* ball = new GameObject();
    ball->setPosition({ 300, 400 });
    ball->addCircleComponent();
    CircleShape* ballShape = ball->getCircleComponent();
    ballShape->circleShape(20.f);
    ballShape->setRGBColor({ 0, 0, 0 });
    ball->addPhysicsComponent();
    Physics* ballPhysics = ball->getPhysicsComponent();
    ballPhysics->setSpeed({ -0.2f, -0.2f });
    ball->addColliderComponent();
    Collider* ballCollider = ball->getColliderComponent();
    ballCollider->createColliderWithSize({ 20.f , 20.f });
    ballCollider->interactsWithVector(objects);

    sf::Clock frameClock;
    // TODO: Hero, mozog, collideol
    while (window.isOpen())
    {
        frameClock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(125, 125, 125));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player->position.x >= 0) {
            player->position.x -= 0.2f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player->position.x <= 600) {
            player->position.x += 0.2f;
        }

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

        std::vector<Collider*> collisions =  ballCollider->isColliding();
        for (auto* collider : Scene::createdColliders) {
            if (collider != nullptr) {
                collider->DrawDebug(window);
            }
        }

        for (auto* detected : collisions) {
            ballPhysics->setSpeed({ ballPhysics->getSpeed().x, -ballPhysics->getSpeed().y });
            if (detected->isDestructible()) {
                delete detected->getGameObject();
            }
        }

        for (auto* circle : Scene::createdCircles) {
            if (circle != nullptr) {
               circle->Draw(window);
            }
        }

        for (auto* physics : Scene::createdPhysics) {
            if (physics != nullptr) {
                physics->update();
            }
        }

        sf::Vector2<float> pos = ball->position;
        sf::Vector2<float> speed = ballPhysics->getSpeed();
        if (pos.x < 0 || pos.x > 750.f) {
            ballPhysics->setSpeed({ -speed.x, speed.y });
        }

        if (pos.y < 0 || pos.y > 550.f) {
            ballPhysics->setSpeed({ speed.x, -speed.y });
        }

        window.display();
    }

    // Cleanup
    for (auto* object : Scene::_createdObjects) {
        delete object;
    }
    return 0;
}
