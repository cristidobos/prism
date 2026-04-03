#pragma once

#include "prism/math/vec.h"

namespace prism {
    struct SurfaceInteraction {
        Float t;
        Point3f point;
        Normal3f normal;

        SurfaceInteraction(Float t, Point3f point, Normal3f normal) : t(t), point(point), normal(normal) {}
    };
}