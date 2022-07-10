#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_VIDEO_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_VIDEO_H

#include <SFML/Graphics.hpp>

#include <cmath>
#include <functional>
#include <memory>

#include "PlasmaEffect.h"
#include "TunnelEffect.h"
#include "FireEffect.h"

struct Video {
    Video(int height, int width);

    void updateDt();

    void handleInput();

    void update();

    void render();

    void run();

private:
    PlasmaEffect plasma;
    TunnelEffect tunnel;
    FireEffect fire;

    sf::Clock dtClock;
    float dt{};

    int height{}, width{};
    std::shared_ptr<sf::RenderWindow> window;
};

#endif  // INC_43_OLDSCHOOLDEMOEFFECTS_VIDEO_H
