#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_TUNNELEFFECT_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_TUNNELEFFECT_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Effect.h"

struct TunnelEffect : Effect {
    TunnelEffect() = default;

    TunnelEffect(const std::shared_ptr<sf::RenderWindow> &window, const sf::Image& image);

    void update(float dt) override;
private:
    std::vector<std::vector<sf::Color>> pixelColor;
    int imageHeight{}, imageWidth{};

    std::vector<std::vector<int>> distanceTable;
    std::vector<std::vector<int>> angleTable;
    float ratio{};
    float shiftX{}, shiftY{};
    float centerShiftX_{}, centerShiftY_{};

    int add(int a, int b, int mod);
};


#endif //INC_43_OLDSCHOOLDEMOEFFECTS_TUNNELEFFECT_H
