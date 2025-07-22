#include "geom/Hull.hpp"
#include <algorithm>
#include <cmath>
#include <iostream> // for debug

/**
 * @brief Cross product (b - a) x (c - a).
 */
static double cross(const Pt& a, const Pt& b, const Pt& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

/**
 * @brief Builds the convex hull using Andrew's monotone chain algorithm.
 * @param pts Vector of points (modified due to sorting).
 * @return Convex hull points in CCW order.
 */
std::vector<Pt> buildHull(std::vector<Pt>& pts) {
    int n = pts.size();
    if (n <= 1) return pts;

    // Sort points by x, then y
    std::sort(pts.begin(), pts.end(), [](const Pt& a, const Pt& b) {
        return (a.x < b.x) || (a.x == b.x && a.y < b.y);
    });

    std::vector<Pt> hull;

    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }

    // Upper hull
    for (int i = n - 2, t = hull.size() + 1; i >= 0; --i) {
        while (hull.size() >= t && cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }

    hull.pop_back();  // Remove duplicate first point

    // Debug print
    std::cerr << "Hull points:\n";
    for (const auto& p : hull) {
        std::cerr << "(" << p.x << ", " << p.y << ")\n";
    }

    return hull;
}

/**
 * @brief Computes the polygon area using the Shoelace formula.
 */
double polygonArea(const std::vector<Pt>& poly) {
    double area = 0.0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }
    return std::fabs(area) / 2.0;
}
