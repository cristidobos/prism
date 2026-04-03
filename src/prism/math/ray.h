#pragma once

#include "prism/math/vec.h"

namespace prism {
    struct Ray {
        Point3f origin;
        Vector3f direction;

        Ray(Point3f o, Vector3f d) : origin(o), direction(d) {}

        [[nodiscard]] Point3f at(Float t) const { return origin + t * direction; }
    };
}