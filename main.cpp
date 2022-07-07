#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <cmath>
#include <functional>

const int HEIGHT = 400;
const int WIDTH = 400;

std::mt19937 rnd(time(0));

int f(float x, float y, float w, float h){
    x /= 2, y /= 2;
    return 128.0 + (128.0 * sin(x / 16.0)) +
    + 128.0 + (128.0 * sin(sqrt(double((x - w / 2.0) * (x - w / 2.0) + (h - 300 / 2.0) * (h - 300 / 2.0))) / 8.0))
    + 128.0 + (128.0 * sin(sqrt(double(x * x + y * y)) / 8.0));
}

struct Palette{
    Palette() = default;

    Palette(const std::function<int(int x)>& redColorFunction, const std::function<int(int x)>& greenColorFunction, const std::function<int(int x)> &blueColorFunction){
        R.resize(256);
        G.resize(256);
        B.resize(256);

        for (int i = 0; i < 256; ++i){
            R[i] = redColorFunction(i);
            G[i] = greenColorFunction(i);
            B[i] = blueColorFunction(i);
        }
    }
    sf::Color getColor(int ind){
        return {R[ind], G[ind], B[ind]};
    }
private:
    std::vector<sf::Uint8> R, G, B;
};


struct Video{
    Video() : window(sf::VideoMode(WIDTH, HEIGHT), "OldSchoolDemoEffects") {
        window.setFramerateLimit(60);

        screen.resize(HEIGHT);
        plasma.resize(HEIGHT);
        for (int y = 0; y < HEIGHT; ++y){
            for (int x = 0; x < WIDTH; ++x){
                screen[y].push_back(sf::RectangleShape());
                screen[y][x].setSize({1, 1});
                screen[y][x].setPosition(sf::Vector2f(x, y));

                plasma[y].push_back(f(x, y, 300, 300));
            }
        }

        auto r = [](int i){return int(128.0 + 128 * sin(3.1415 * i / 16.0)); };
        auto g = [](int i){return int(128.0 + 128 * sin(3.1415 * i / 32.0)); };
        auto b = [](int i){return int(128.0 + 128 * sin(3.1415 * i / 8.0)); };
        palette = Palette(r, g, b);

        shift = 1;
        dt = 1;

    }

    void updateDt() { dt = dtClock.restart().asSeconds();}

    void handleInput(){
        sf::Event sfEvent{};
        while(window.pollEvent(sfEvent)){
            if (sfEvent.type == sf::Event::Closed){
                window.close();
                exit(0);
            }
    sf::Time time;
        }
    }

    void update() {
        handleInput();

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                int ind = (plasma[y][x] + int(shift)) % 256;
                screen[y][x].setFillColor(palette.getColor(ind));
            }
        }

        shift += 90 * dt;
        if (shift >= 256.0) { shift -= 256.0; }
    }

    void render(){
        window.clear();
        for (int y = 0; y < HEIGHT; ++y){
            for (int x = 0; x < WIDTH; ++x){
                window.draw(screen[y][x]);
            }
        }
        window.display();
    }

    void run(){
        while(window.isOpen()){
            updateDt();
            update();
            render();
        }
    }
private:
    std::vector<std::vector<sf::RectangleShape>> screen;
    std::vector<std::vector<int>> plasma;
    Palette palette;

    sf::RenderWindow window;

    sf::Clock dtClock;
    float dt;
    float shift;
};

int main()
{
    Video video;
    video.run();
}

