#pragma once

#include "prism/math/ray.h"
#include "prism/types.h"

namespace prism {
    struct Camera {
        Float fov;
        Float aspectRatio;
        Point3f pos;
        Vector3f forward, right, up;
        Float halfHeight, halfWidth;

        Camera(Point3f position, Point3f lookAt, Vector3f up, Float fov, Float aspectRatio)
            : fov(fov), aspectRatio(aspectRatio), pos(position) {
            forward = normalize(lookAt - position);
            right = normalize(cross(forward, up));
            this->up = cross(right, forward);

            halfHeight = glm::tan(glm::radians(fov) / Float(2));
            halfWidth = halfHeight * aspectRatio;
        }

        [[nodiscard]] Ray generateRay(Float x, Float y) const {
            Vector3f dir = forward + x * halfWidth * right + y * halfHeight * up;
            return {pos, normalize(dir)};
        }
    };
}