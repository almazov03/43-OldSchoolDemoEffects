#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_PALETTE_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_PALETTE_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

struct HsvColor{
    int h, s, v;
};

sf::Color hsvToRgb(HsvColor);

struct Palette {
    Palette() = default;

    Palette(const std::function<HsvColor(int x)> &hsvFunction);

    Palette(const std::function<sf::Uint8 (int x)> &redColorFunction,
            const std::function<sf::Uint8 (int x)> &greenColorFunction,
            const std::function<sf::Uint8 (int x)> &blueColorFunction);

    [[nodiscard]] sf::Color getColor(int ind) const;
    const sf::Color& operator[] (int ind) const;
    sf::Color& operator[] (int ind);

private:
    std::vector<sf::Color> palette;
};

#endif //INC_43_OLDSCHOOLDEMOEFFECTS_PALETTE_H
