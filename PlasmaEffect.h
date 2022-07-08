#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <vector>

struct PlasmaEffect {
    PlasmaEffect() = default;
    PlasmaEffect(const std::shared_ptr<sf::RenderWindow> &window,
                 const std::function<int(int x, int y)> &indFunction,
                 const std::function<int(int x)> &redColorFunction,
                 const std::function<int(int x)> &greenColorFunction,
                 const std::function<int(int x)> &blueColorFunction);

    void update(float dt);
    void render();

private:
    struct Palette {
        Palette() = default;

        Palette(const std::function<int(int x)> &redColorFunction,
                const std::function<int(int x)> &greenColorFunction,
                const std::function<int(int x)> &blueColorFunction);

        [[nodiscard]] sf::Color getColor(int ind) const;

    private:
        std::vector<sf::Uint8> R, G, B;
    } palette;

    std::vector<std::vector<sf::RectangleShape>> screen;
    std::vector<std::vector<int>> plasma;
    float colorShift{};

    int height{}, width{};
    std::shared_ptr<sf::RenderWindow> window;
};

#endif  // INC_43_OLDSCHOOLDEMOEFFECTS_PLASMAEFFECT_H
