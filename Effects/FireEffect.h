#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_FIREEFFECT_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_FIREEFFECT_H

#include <random>

#include "Effect.h"
#include "Palette.h"

struct FireEffect : Effect {
    FireEffect() = default;

    FireEffect(const std::shared_ptr<sf::RenderWindow> &window, const Palette &palette);

    void update(float dt) override;
private:
    std::vector<std::vector<int>> fire;
    Palette palette;

    std::mt19937 rnd;
};


#endif //INC_43_OLDSCHOOLDEMOEFFECTS_FIREEFFECT_H
