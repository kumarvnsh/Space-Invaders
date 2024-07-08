// EnemyView.cpp
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy {
    EnemyView::EnemyView(EnemyController* controller)
        : controller(controller), texturePath("path/to/texture.png"), width(50.0f), height(50.0f) {}

    EnemyView::~EnemyView() {}

    void EnemyView::initialize() {
        loadTexture();
        initializeSprite();
        scaleSprite();
    }

    void EnemyView::loadTexture() {
        if (!texture.loadFromFile(texturePath)) {
            // Handle error
        }
    }

    void EnemyView::initializeSprite() {
        sprite.setTexture(texture);
        sprite.setPosition(controller->getPosition());
    }

    void EnemyView::scaleSprite() {
        sprite.setScale(width / texture.getSize().x, height / texture.getSize().y);
    }

    void EnemyView::render(sf::RenderWindow& window) {
        window.draw(sprite);
    }
}
