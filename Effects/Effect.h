#ifndef INC_43_OLDSCHOOLDEMOEFFECTS_EFFECT_H
#define INC_43_OLDSCHOOLDEMOEFFECTS_EFFECT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

struct Effect {
    Effect() = default;

    Effect(const std::shared_ptr<sf::RenderWindow>& window);

    virtual void update(float dt) = 0;

    virtual void render();

protected:
    int height{}, width{};
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<std::vector<sf::RectangleShape>> screen;
};


#endif //INC_43_OLDSCHOOLDEMOEFFECTS_EFFECT_H
