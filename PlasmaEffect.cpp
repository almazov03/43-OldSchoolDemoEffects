#include "PlasmaEffect.h"

PlasmaEffect::PlasmaEffect(const std::shared_ptr<sf::RenderWindow> &window,
                           const std::function<int(int x, int y)> &indFunction,
                           const std::function<int(int x)> &redColorFunction,
                           const std::function<int(int x)> &greenColorFunction,
                           const std::function<int(int x)> &blueColorFunction) {
    this->window = window;
    height = window->getSize().y;
    width = window->getSize().x;

    screen.resize(height);
    plasma.resize(height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            screen[y].push_back(sf::RectangleShape());
            screen[y][x].setSize({1, 1});
            screen[y][x].setPosition(sf::Vector2f(x, y));

            plasma[y].push_back(indFunction(x, y));
        }
    }

    palette = Palette(redColorFunction, greenColorFunction, blueColorFunction);
}

void PlasmaEffect::update(float dt) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int ind = (plasma[y][x] + int(colorShift)) % 256;
            screen[y][x].setFillColor(palette.getColor(ind));
        }
    }

    colorShift += 90 * dt;
    if (colorShift >= 256.0) {
        colorShift -= 256.0;
    }
}

void PlasmaEffect::render() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            window->draw(screen[y][x]);
        }
    }
}

PlasmaEffect::Palette::Palette(
    const std::function<int(int)> &redColorFunction,
    const std::function<int(int)> &greenColorFunction,
    const std::function<int(int)> &blueColorFunction) {
    R.resize(256);
    G.resize(256);
    B.resize(256);

    for (int i = 0; i < 256; ++i) {
        R[i] = redColorFunction(i);
        G[i] = greenColorFunction(i);
        B[i] = blueColorFunction(i);
    }
}

sf::Color PlasmaEffect::Palette::getColor(int ind) const {
    return {R[ind], G[ind], B[ind]};
}
