#include <SFML/Graphics.hpp>
#include <iostream>

#include "Header/GraphicService.h"
#include "Header/GameService.h"

//class Player {
//private:
//    int health = 3;
//    sf::Vector2f position;
//    float movement_speed = 0.5f; // Reduced movement speed for less sensitivity
//    int player_score = 0;
//
//public:
//    sf::Texture player_texture;
//    sf::Sprite player_sprite;
//
//    Player(float startX, float startY) {
//        position = sf::Vector2f(startX, startY);
//    }
//
//    int getScore() {
//        return player_score;
//    }
//
//    void setScore(int newScore) {
//        player_score = newScore;
//    }
//
//    sf::Vector2f getPosition() {
//        return position;
//    }
//
//    void takeDamage() {}
//
//    void move(float offsetX) {
//        position.x += offsetX * movement_speed;
//        if (position.x < 25) position.x = 25; // Adjusted boundary for left side
//        if (position.x > 725) position.x = 725; // Adjusted boundary for right side (assuming sprite width is 50)
//    }
//
//    void shootBullets() {}
//};

int main() {
    //sf::VideoMode videoMode = sf::VideoMode(800, 600); // Define the video mode (dimensions)
    //sf::RenderWindow window(videoMode, "SFML Window"); // Create a window object

    //Player player(375.0f, 500.0f); // Create the player object at bottom center, slightly up

    //if (!player.player_texture.loadFromFile("assets/textures/player_ship.png")) { // Load the player ship texture
    //    std::cerr << "Error loading player ship texture" << std::endl;
    //    return -1;
    //}

    //player.player_sprite.setTexture(player.player_texture); // Set the player sprite variable
    //player.player_sprite.setScale(0.5f, 0.5f); // Scale the player sprite to make it smaller

    //while (window.isOpen()) {
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        // Check for window closure
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    // Handle keyboard input
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //        player.move(-0.5f);
    //    }
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //        player.move(0.5f);
    //    }

    //    // Clear the window
    //    window.clear(sf::Color::Black); // This code will set a blue background color (optional)

    //    player.player_sprite.setPosition(player.getPosition()); // Set the position of the player sprite

    //    window.draw(player.player_sprite); // Draw the player sprite

    //    window.display(); // Display what was drawn
    //}

    GameService* game_service = new GameService();
    game_service->Ignite();

    while (game_service->isRunning()) {
        game_service->update();
        game_service->render();
    }

    delete game_service;
    return 0;
}
