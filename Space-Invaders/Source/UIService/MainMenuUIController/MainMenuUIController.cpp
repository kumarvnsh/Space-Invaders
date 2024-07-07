#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GameService/GameService.h"

namespace UI {
    namespace MainMenu {
        MainMenuUIController::MainMenuUIController() {
            game_window = nullptr;
        }

        void MainMenuUIController::initialize(sf::RenderWindow* window) {
            game_window = window;
            initializeBackgroundImage();
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage() {
            if (background_texture.loadFromFile(background_texture_path)) {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuUIController::scaleBackgroundImage() {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeButtons() {
            if (loadButtonTexturesFromFile()) {
                setButtonSprites();
                scaleAllButtons();
                positionButtons();
            }
        }

        bool MainMenuUIController::loadButtonTexturesFromFile() {
            return play_button_texture.loadFromFile(play_button_texture_path) &&
                instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(quit_button_texture_path);
        }

        void MainMenuUIController::setButtonSprites() {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }

        void MainMenuUIController::scaleAllButtons() {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale) {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::positionButtons() {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            play_button_sprite.setPosition({ x_position, 500.f });
            instructions_button_sprite.setPosition({ x_position, 700.f });
            quit_button_sprite.setPosition({ x_position, 900.f });
        }

        void MainMenuUIController::update() {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (isButtonClicked(play_button_sprite)) {
                    GameService::setCurrentState(GameState::GAMEPLAY);
                }
                else if (isButtonClicked(instructions_button_sprite)) {
                    // Handle instructions button click
                }
                else if (isButtonClicked(quit_button_sprite)) {
                    game_window->close();
                }
            }
        }

        bool MainMenuUIController::isButtonClicked(const sf::Sprite& button) {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);
            sf::FloatRect button_bounds = button.getGlobalBounds();
            return button_bounds.contains(static_cast<sf::Vector2f>(mouse_position));
        }

        void MainMenuUIController::render() {
            game_window->draw(background_sprite);
            game_window->draw(play_button_sprite);
            game_window->draw(instructions_button_sprite);
            game_window->draw(quit_button_sprite);
        }
    }
}
