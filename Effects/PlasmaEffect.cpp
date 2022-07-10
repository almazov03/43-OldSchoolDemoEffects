#include "PlasmaEffect.h"

PlasmaEffect::PlasmaEffect(const std::shared_ptr<sf::RenderWindow> &window,
                           const std::function<int(int x, int y)> &plasmaFunction,
                           const Palette &palette) : Effect(window) {
    plasma.resize(height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            plasma[y].push_back(plasmaFunction(x, y));
        }
    }

    this->palette = palette;
}

void PlasmaEffect::update(float dt) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int ind = (plasma[y][x] + int(colorShift)) % 256;
            screen[y][x].setFillColor(palette[ind]);
        }
    }

    colorShift += 90 * dt;
    if (colorShift >= 256.0) {
        colorShift -= 256.0;
    }
}