#include "core/State.hpp"
#include "geom/Hull.hpp"
#include <iostream>
#include <algorithm>

void State::newGraph(int n) {
    points.clear();
    points.reserve(n);
    std::cerr << "New graph created with capacity " << n << "\n";
}

void State::addPoint(double x, double y) {
    points.push_back({x, y});
    std::cerr << "Added point (" << x << ", " << y << ")\n";
}

void State::removePoint(double x, double y) {
    auto it = std::remove_if(points.begin(), points.end(),
        [&](const Pt& p) { return p.x == x && p.y == y; });
    if (it != points.end()) {
        points.erase(it, points.end());
        std::cerr << "Removed point (" << x << ", " << y << ")\n";
    } else {
        std::cerr << "Point (" << x << ", " << y << ") not found.\n";
    }
}

void State::computeCH() const {
    if (points.size() < 3) {
        std::cout << "0.000000\n";
        return;
    }

    std::vector<Pt> temp = points; 
    auto hull = buildHull(temp);
    double area = polygonArea(hull);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << area << "\n";
}
