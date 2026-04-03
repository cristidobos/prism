#pragma once

#include <glm/glm.hpp>
#include "prism/types.h"

namespace prism {
    struct Color {
        glm::vec<3, Float> v;

        Color() = default;
        Color(Float r, Float g, Float b) : v(r, g, b) {}
        explicit Color(glm::vec<3, Float> v) : v(v) {}

        Color& operator+=(const Color& other) {
            v += other.v;
            return *this;
        }
    };

    inline Color operator+(Color c1, Color c2) { c1 += c2; return c1; }


}