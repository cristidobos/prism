#pragma once

#include <glm/glm.hpp>
#include "prism/types.h"

namespace prism {
    struct Vector3f {
        glm::vec<3, Float> v;

        Vector3f() = default;
        Vector3f(Float x, Float y, Float z) : v{x, y, z} {}
        explicit Vector3f(glm::vec<3, Float> v) : v{v} {}
    };

    struct Point3f {
        glm::vec<3, Float> v;

        Point3f() = default;
        Point3f(Float x, Float y, Float z) : v{x, y, z} {}
        explicit Point3f(glm::vec<3, Float> v) : v{v} {}
    };

    struct Normal3f {
        glm::vec<3, Float> v;

        Normal3f() = default;
        Normal3f(Float x, Float y, Float z) : v{x, y, z} {}
        explicit Normal3f(glm::vec<3, Float> v) : v{v} {}
        explicit Normal3f(Vector3f v) : v{v.v} {}
    };


    inline Vector3f operator+(Vector3f a, Vector3f b) { return {a.v.x + b.v.x, a.v.y + b.v.y, a.v.z + b.v.z}; }
    inline Vector3f operator-(Vector3f a, Vector3f b) { return {a.v.x - b.v.x, a.v.y - b.v.y, a.v.z - b.v.z}; }
    inline Vector3f operator*(Float t, Vector3f v) { return {t * v.v.x, t * v.v.y, t * v.v.z}; }
    inline Vector3f operator*(Vector3f v, Float t) { return {t * v.v.x, t * v.v.y, t * v.v.z}; }
    inline Vector3f operator-(Point3f a, Point3f b) { return {a.v.x - b.v.x, a.v.y - b.v.y, a.v.z - b.v.z}; }

    inline Vector3f operator-(Vector3f v) { return {-v.v.x, -v.v.y, -v.v.z}; }
    inline Normal3f operator-(Normal3f n) { return {-n.v.x, -n.v.y, -n.v.z}; }

    inline Point3f operator+(Point3f p, Vector3f v) { return {p.v.x + v.v.x, p.v.y + v.v.y, p.v.z + v.v.z}; }
    inline Point3f operator-(Point3f p, Vector3f v) { return {p.v.x - v.v.x, p.v.y - v.v.y, p.v.z - v.v.z}; }
    inline Point3f operator*(Float t, Point3f p) { return {t * p.v.x, t * p.v.y, t * p.v.z}; }

    inline Float length(Vector3f v) { return glm::length(v.v); }
    inline Float length(Normal3f n) { return glm::length(n.v); }

    inline Vector3f normalize(Vector3f v) {
        Float l = length(v);
        return {v.v.x / l, v.v.y / l, v.v.z / l};
    }
    inline Normal3f normalize(Normal3f n) {
        Float l = length(n);
        return {n.v.x / l, n.v.y / l, n.v.z / l};
    }

    inline Float dot(Vector3f a, Vector3f b) { return glm::dot(a.v, b.v); }
    inline Float dot(Normal3f a, Normal3f b) { return glm::dot(a.v, b.v); }
    inline Float dot(Normal3f n, Vector3f v) { return glm::dot(n.v, v.v); }

    inline Normal3f faceforward(Normal3f n, Vector3f v) {
        if (glm::dot(n.v, v.v) < 0) return -n;
        return n;
    }

    inline Vector3f cross(Vector3f a, Vector3f b) { return Vector3f(glm::cross(a.v, b.v)); }

}
