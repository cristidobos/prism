#include <fstream>
#include <algorithm>
#include "film.h"

namespace prism {
    Film::Film(int width, int height) : width(width), height(height), pixels(width * height) {}

    void Film::addSample(int x, int y, Color color) {
        if (x < 0 || x >=width || y < 0 || y >= height) return;
        pixels[y * width + x] += color;
    }

    void Film::writeToFile(const std::string& path) const {
        std::ofstream file(path);
        if (!file.is_open()) return;

        file << "P3\n" << width << " " << height << "\n255\n";
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                const Color& color = pixels[y * width + x];
                int r = static_cast<int>(std::clamp(color.v.r, Float(0), Float(1)) * 255);
                int g = static_cast<int>(std::clamp(color.v.g, Float(0), Float(1)) * 255);
                int b = static_cast<int>(std::clamp(color.v.b, Float(0), Float(1)) * 255);
                file << r << " " << g << " " << b << "\n";
            }
        }
    }

}
