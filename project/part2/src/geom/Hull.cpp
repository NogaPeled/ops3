#include "geom/Hull.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

/**
 * @brief Cross product (b - a) x (c - a).
 */
static double cross(const Pt& a, const Pt& b, const Pt& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

/**
 * @brief Constructs the strict convex hull using Graham Scan algorithm,
 *        popping points that cause right turns or lie inside collinear edges.
 *        Ensures hull is CCW ordered for correct polygon area.
 * @param pts Input vector of points.
 * @return Vector of points forming the convex hull in CCW order.
 */
std::vector<Pt> buildHull(std::vector<Pt>& pts) {
    constexpr double EPS = 1e-9;

    if (pts.size() <= 1) return pts;

    // Find pivot (lowest y, then lowest x)
    auto pivot = *std::min_element(pts.begin(), pts.end(), [](const Pt& a, const Pt& b) {
        return (a.y < b.y) || (a.y == b.y && a.x < b.x);
    });

    // Sort points by polar angle from pivot
    std::sort(pts.begin(), pts.end(), [pivot](const Pt& a, const Pt& b) {
        double angleA = atan2(a.y - pivot.y, a.x - pivot.x);
        double angleB = atan2(b.y - pivot.y, b.x - pivot.x);
        if (fabs(angleA - angleB) < EPS) {
            double distA = hypot(a.x - pivot.x, a.y - pivot.y);
            double distB = hypot(b.x - pivot.x, b.y - pivot.y);
            return distA < distB;
        }
        return angleA < angleB;
    });

    // Build hull using Graham Scan, popping right turns or inside collinear points
    std::vector<Pt> hull;
    for (auto& p : pts) {
        while (hull.size() >= 2) {
            double c = cross(hull[hull.size() - 2], hull.back(), p);
            bool rightTurn = c < -EPS;
            bool collinearInside = fabs(c) < EPS &&
                (hypot(p.x - hull[hull.size() - 2].x, p.y - hull[hull.size() - 2].y) >
                 hypot(hull.back().x - hull[hull.size() - 2].x, hull.back().y - hull[hull.size() - 2].y));
            if (rightTurn || collinearInside) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }

    // Ensure CCW order for polygon area correctness
    auto signedArea = [](const std::vector<Pt>& poly) -> double {
        double area = 0.0;
        int n = poly.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
        }
        return area / 2.0;
    };

    double area = signedArea(hull);
    if (area < 0) {  // reverse if polygon is clockwise (negative area)
        std::reverse(hull.begin(), hull.end());
    }

    // Print hull points in CCW order
    std::cout << "Hull points:\n";
    for (auto& p : hull) {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return hull;
}

/**
 * @brief Computes the area of a polygon using the Shoelace formula.
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
