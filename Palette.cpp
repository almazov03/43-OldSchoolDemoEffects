#include "Palette.h"

Palette::Palette(const std::function<sf::Uint8 (int)> &redColorFunction, const std::function<sf::Uint8 (int)> &greenColorFunction,
                 const std::function<sf::Uint8 (int)> &blueColorFunction) {
    palette.resize(256);
    for (int i = 0; i < 256; ++i) {
        palette[i] = {redColorFunction(i),
                    greenColorFunction(i),
                     blueColorFunction(i)};
    }
}

Palette::Palette(const std::function<HsvColor(int)> &HsvFunction) {
    palette.resize(256);
    for (int i = 0; i < 256; ++i){
        palette[i] = hsvToRgb(HsvFunction(i));
    }
}

sf::Color Palette::getColor(int ind) const {
    return palette[ind];
}

const sf::Color &Palette::operator[](int ind) const {
    return palette[ind];
}

sf::Color &Palette::operator[](int ind) {
    return palette[ind];
}


sf::Color hsvToRgb(HsvColor hsv) {
    sf::Color rgb;

    if (hsv.s == 0) {
        rgb.r = hsv.v;
        rgb.g = hsv.v;
        rgb.b = hsv.v;
        return rgb;
    }

    unsigned char region = hsv.h / 43;
    unsigned char remainder = (hsv.h - (region * 43)) * 6;
    unsigned char p = (hsv.v * (255 - hsv.s)) >> 8;
    unsigned char q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
    unsigned char t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;

    switch (region) {
        case 0:
            rgb.r = hsv.v;
            rgb.g = t;
            rgb.b = p;
            break;
        case 1:
            rgb.r = q;
            rgb.g = hsv.v;
            rgb.b = p;
            break;
        case 2:
            rgb.r = p;
            rgb.g = hsv.v;
            rgb.b = t;
            break;
        case 3:
            rgb.r = p;
            rgb.g = q;
            rgb.b = hsv.v;
            break;
        case 4:
            rgb.r = t;
            rgb.g = p;
            rgb.b = hsv.v;
            break;
        default:
            rgb.r = hsv.v;
            rgb.g = p;
            rgb.b = q;
            break;
    }

    return rgb;
}


