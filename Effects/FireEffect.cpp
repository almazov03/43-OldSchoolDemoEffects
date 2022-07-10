#include "FireEffect.h"

FireEffect::FireEffect(const std::shared_ptr<sf::RenderWindow> &window,
                       const Palette &palette) : Effect(window), rnd(time(0)) {
    this->palette = palette;

    fire.resize(height, std::vector<int>(width));
}

void FireEffect::update(float dt) {
    for (int x = 0; x < width; ++x){
        fire[height - 1][x] = rnd() % 256;
    }

    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            fire[y][x] =
                    ((fire[(y + 1) % height][(x - 1 + width) % width]
                      + fire[(y + 2) % height][(x) % width]
                      + fire[(y + 1) % height][(x + 1) % width]
                      + fire[(y + 3) % height][(x) % width])
                     * 64) / 257;

            screen[y][x].setFillColor(palette[fire[y][x]]);
        }
    }
}
