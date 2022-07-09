#include "Video.h"

Video::Video(int height, int width) {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(width, height),
                                                "OldSchoolDemoEffects");
    window->setFramerateLimit(60);
    this->height = height;
    this->width = width;


///---------------------PLASMA---------------------------------------
    auto r = [](int i) { return int(128.0 + 128 * sin(3.1415 * i / 32.0)); };
    auto g = [](int i) { return int(128.0 + 128 * sin(3.1415 * i / 64.0)); };
    auto b = [](int i) { return int(128.0 + 128 * sin(3.1415 * i / 128.0)); };
    auto f = [&height, &width](float x, float y) {
        float h = height / 2.0;
        float w = width / 2.0;
        x /= 2.0, y /= 2.0;
        return 128.0 + (128.0 * cos(x / 16.0)) + 128.0 +
               (128.0 *
                cos(sqrt(double((x - w) * (x - w) + (y - h) * (y - h))) /
                    8.0)) +
               128.0 + (128.0 * cos(sqrt(double(x * x + y * y)) / 8.0));
    };

    plasma = PlasmaEffect(window, f, r, g, b);
///---------------------PLASMA---------------------------------------

///---------------------TUNNEL---------------------------------------
    sf::Image image;
    image.loadFromFile("../lol2.png");
    tunnel = TunnelEffect(window, image);
///---------------------TUNNEL---------------------------------------
}

void Video::updateDt() {
    dt = dtClock.restart().asSeconds();
}

void Video::handleInput() {
    sf::Event sfEvent{};
    while (window->pollEvent(sfEvent)) {
        if (sfEvent.type == sf::Event::Closed) {
            window->close();
            exit(0);
        }
    }
}

void Video::update() {
    updateDt();
    handleInput();
//    plasma.update(dt);
    tunnel.update(dt);
}

void Video::render() {
    window->clear();
//    plasma.render();
    tunnel.render();
    window->display();
}

void Video::run() {
    while (window->isOpen()) {
        update();
        render();
    }
}
