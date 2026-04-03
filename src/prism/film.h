#pragma once

#include <string>
#include <vector>
#include "prism/color.h"

namespace prism {
    class Film {
        public:
            Film(int width, int height);
            void addSample(int x, int y, Color color);
            void writeToFile(const std::string& path) const;
        private:
            int width, height;
            std::vector<Color> pixels;
    };
}