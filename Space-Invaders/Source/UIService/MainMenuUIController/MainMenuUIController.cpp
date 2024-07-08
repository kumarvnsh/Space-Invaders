#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/ServiceLocator/ServiceLocator.h"
#include "../../Header/GameService/GameService.h"
#include "../../Header/EventService/EventService.h"
#include <iostream>

namespace UI {
    namespace MainMenu {
        MainMenuUIController::MainMenuUIController() {
            game_window = nullptr;
        }

        void MainMenuUIController::initialize(sf::RenderWindow* window) {
            game_window = window;
            std::cout << "Initializing background image" << std::endl;
            initializeBackgroundImage();
            std::cout << "Initializing buttons" << std::endl;
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage() {
            std::cout << "Loading background texture from: " << background_texture_path << std::endl;
            if (background_texture.loadFromFile(background_texture_path)) {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
                std::cout << "Background texture loaded successfully.\n";
            }
            else {
                std::cerr << "Failed to load background texture from " << background_texture_path << "\n";
            }
        }

        void MainMenuUIController::scaleBackgroundImage() {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeButtons() {
            std::cout << "Loading button textures...\n";
            if (loadButtonTexturesFromFile()) {
                setButtonSprites();
                scaleAllButtons();
                positionButtons();
                std::cout << "Button textures loaded successfully.\n";
            }
            else {
                std::cerr << "Failed to load one or more button textures.\n";
            }
        }

        bool MainMenuUIController::loadButtonTexturesFromFile() {
            bool play_loaded = play_button_texture.loadFromFile(play_button_texture_path);
            bool instructions_loaded = instructions_button_texture.loadFromFile(instructions_button_texture_path);
            bool quit_loaded = quit_button_texture.loadFromFile(quit_button_texture_path);

            return play_loaded && instructions_loaded && quit_loaded;
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

            play_button_sprite.setPosition(x_position, 500.f);
            instructions_button_sprite.setPosition(x_position, 700.f);
            quit_button_sprite.setPosition(x_position, 900.f);
        }

        void MainMenuUIController::update() {
            if (ServiceLocator::getInstance()->getEventService()->leftMouseClicked()) {
                processButtonInteractions();
            }
        }

        void MainMenuUIController::processButtonInteractions() {
            if (clickedButton(play_button_sprite)) {
                GameService::setCurrentState(GameService::GameState::GAMEPLAY);
            }
            else if (clickedButton(instructions_button_sprite)) {
                // Handle instructions button click
            }
            else if (clickedButton(quit_button_sprite)) {
                game_window->close();
            }
        }

        bool MainMenuUIController::clickedButton(const sf::Sprite& button) {
            sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);
            sf::FloatRect button_bounds = button.getGlobalBounds();
            return button_bounds.contains(static_cast<sf::Vector2f>(mouse_position));
        }



        void MainMenuUIController::render() {
            std::cout << "Rendering background\n";
            game_window->draw(background_sprite);

            std::cout << "Rendering play button\n";
            game_window->draw(play_button_sprite);

            std::cout << "Rendering instructions button\n";
            game_window->draw(instructions_button_sprite);

            std::cout << "Rendering quit button\n";
            game_window->draw(quit_button_sprite);
        }

    }
}
