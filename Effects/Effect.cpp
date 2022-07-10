#include "Effect.h"

void Effect::render() {
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            window->draw(screen[y][x]);
        }
    }
}

Effect::Effect(const std::shared_ptr<sf::RenderWindow>& window) {
    this->window = window;
    height = window->getSize().y;
    width = window->getSize().x;

    screen.resize(height);
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            screen[y].push_back(sf::RectangleShape());
            screen[y][x].setSize({1, 1});
            screen[y][x].setPosition(sf::Vector2f(x, y));
        }
    }
}
