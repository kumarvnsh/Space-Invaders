#include "../../header/Enemy/EnemyView.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../header/Enemy/EnemyController.h" 
#include <iostream>

namespace Enemy {
    EnemyView::EnemyView(EnemyController* controller) : enemy_controller(controller) {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    EnemyView::~EnemyView() {}

    void EnemyView::initialize() {
        initializeEnemySprite(enemy_controller->getEnemyType());
    }

    void EnemyView::initializeEnemySprite(EnemyConfig::EnemyType type) {
        switch (type) {
        case EnemyConfig::EnemyType::SUBZERO:
            if (enemy_texture.loadFromFile(subzero_texture_path)) {
                enemy_sprite.setTexture(enemy_texture);
                scaleEnemySprite();
            }
            break;
        case EnemyConfig::EnemyType::ZAPPER:
            if (enemy_texture.loadFromFile(zapper_texture_path)) {
                enemy_sprite.setTexture(enemy_texture);
                scaleEnemySprite();
            }
            break;
        default:
            break;
        }
    }

    void EnemyView::scaleEnemySprite() {
        enemy_sprite.setScale(
            static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
            static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
        );
    }

    void EnemyView::update() {
        enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
    }

    void EnemyView::render() {
        game_window->draw(enemy_sprite);
    }
}
