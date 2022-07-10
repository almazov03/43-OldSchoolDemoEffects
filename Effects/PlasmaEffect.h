#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H

#include <SFML/Graphics.hpp>

#include "Effect.h"
#include "Palette.h"

struct PlasmaEffect : Effect {
    PlasmaEffect() = default;

    PlasmaEffect(const std::shared_ptr<sf::RenderWindow> &window,
                 const std::function<int(int x, int y)> &plasmaFunction,
                 const Palette &palette);

    void update(float dt) override;
private:
    Palette palette;

    std::vector<std::vector<int>> plasma;
    float colorShift{};
};

#endif  // INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H
