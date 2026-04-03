#pragma once

#include <optional>
#include "prism/math/vec.h"
#include "prism/math/ray.h"
#include "prism/interaction.h"

namespace prism {
    struct Sphere {
        Point3f center;
        Float radius;

        Sphere(Point3f center, Float radius) : center(center), radius(radius) {}

        [[nodiscard]] std::optional<SurfaceInteraction> intersect(const Ray& ray) const {
            Vector3f L = ray.origin - center;
            Float Ld = dot(L, ray.direction);
            Float d2 = dot(ray.direction, ray.direction);
            Float L2 = dot(L, L);

            Float discriminant = 4 * Ld * Ld - 4 * d2 * (L2 - radius * radius);

            if (discriminant < 0) return std::nullopt;

            Float t1 = (-Ld + glm::sqrt(discriminant)) / (2 * d2);
            Float t2 = (-Ld - glm::sqrt(discriminant)) / (2 * d2);

            Float t = t1 < t2 ? t1 : t2;
            if (t < 0) t = t1 < t2 ? t2 : t1;
            if (t < 0) return std::nullopt;

            Point3f point = ray.at(t);
            auto normal = Normal3f((point - center) * (Float(1) / radius));
            return SurfaceInteraction(t, point, normal);
        }
    };
}