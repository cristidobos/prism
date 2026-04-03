#include "film.h"
#include "math/ray.h"
#include "camera.h"
#include "shapes/sphere.h"

int main() {
    int width = 800, height = 400;
    prism::Film film(width, height);
    prism::Camera camera(prism::Point3f(0, 0, 1), prism::Point3f(0, 0, 0),
        prism::Vector3f(0, 1, 0), prism::Float(90), prism::Float(2));
    prism::Sphere sphere(prism::Point3f(0, 0, 0), prism::Float(0.5));

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            prism::Float x_normalized = (static_cast<prism::Float>(x) + prism::Float(0.5)) / static_cast<prism::Float>(width) * prism::Float(2) - prism::Float(1);
            prism::Float y_normalized = (static_cast<prism::Float>(y) + prism::Float(0.5)) / static_cast<prism::Float>(height) * prism::Float(2) - prism::Float(1);

            prism::Ray ray = camera.generateRay(x_normalized, y_normalized);
            // std::optional<prism::SurfaceInteraction> interaction = sphere.intersect(ray);
            if (auto interaction = sphere.intersect(ray)) {
                prism::Color color((interaction->normal.v.x + 1) * prism::Float(0.5), (interaction->normal.v.y + 1) * prism::Float(0.5), (interaction->normal.v.z + 1) * prism::Float(0.5));
                film.addSample(x, y, color);
            } else {
                film.addSample(x, y, prism::Color());
            }
        }
    }

    film.writeToFile("result.ppm");
}