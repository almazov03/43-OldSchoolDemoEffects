#include "TunnelEffect.h"

TunnelEffect::TunnelEffect(const std::shared_ptr<sf::RenderWindow> &window,
                           const sf::Image &image) : Effect(window) {
    imageHeight = image.getSize().y;
    imageWidth = image.getSize().x;
    pixelColor.resize(imageHeight);
    for (int y = 0; y < imageHeight; ++y){
        for (int x = 0; x < imageWidth; ++x){
            pixelColor[y].push_back(image.getPixel(x, y));
        }
    }

    ratio = 32.0;
    shiftX = shiftY = centerShiftX_ = centerShiftY_ = 0;

    distanceTable.resize(2 * height);
    angleTable.resize(2 * height);
    for (int y = 0; y < 2 * height; ++y){
        for (int x = 0; x < 2 * width; ++x){
            if (x == width && y == height){
                angleTable[y].push_back(0);
                distanceTable[y].push_back(0);
            }
            int dx = (x - width);
            int dy = (y - height);
            int distance = int(ratio * imageHeight / sqrtl(dx * dx + dy * dy)) % imageHeight;
            int angle = (0.5 * imageWidth * (atan2(dy, dx) + 3.141592) / 3.141592);
            distanceTable[y].push_back(distance);
            angleTable[y].push_back(angle);
        }
    }
}

void TunnelEffect::update(float dt) {
    float centerShiftX = width / 2.0 + 0.5 * (width / 2.0 * sin(centerShiftX_));
    float centerShiftY = height / 2.0 + 0.25 * (height / 2.0 * sin(centerShiftY_));
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            int newY = add(distanceTable[int(y + centerShiftY)][int(x + centerShiftX)], shiftY, imageHeight);
            int newX = add(angleTable[int(y + centerShiftY)][int(x + centerShiftX)], shiftX, imageWidth);
            screen[y][x].setFillColor(pixelColor[newY][newX]);
        }
    }

    shiftY += 40 * dt;
    if (shiftY >= imageHeight){
        shiftY -= imageHeight;
    }

    shiftX += 20 * dt;
    if (shiftX >= imageWidth){
        shiftX -= imageWidth;
    }

    centerShiftX_ += 0.25 * dt;
    if (centerShiftX_ >= 2 * 3.1415){
        centerShiftX_ -= 2 * 3.1415;
    }

    centerShiftY_ += 0.25 * dt;
    if (centerShiftY_ >= 2 * 3.1415){
        centerShiftY_ -= 2 * 3.1415;
    }
}

int TunnelEffect::add(int a, int b, int mod) {
    return (a + b >= mod ? a + b - mod : a + b);
}

