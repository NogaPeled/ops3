#include "core/State.hpp"
#include "geom/Hull.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <chrono>

using namespace std::chrono;

void State::newGraphVector(int n) {
    points.clear();
    points.reserve(n);
    std::cerr << "Vector: New graph created with capacity " << n << "\n";
}

void State::addPointVector(double x, double y) {
    auto start = high_resolution_clock::now();
    points.push_back({x, y});
    auto end = high_resolution_clock::now();
    std::cerr << "Vector: addPoint took " << duration_cast<microseconds>(end - start).count() << " us\n";
}

void State::removePointVector(double x, double y) {
    auto start = high_resolution_clock::now();
    auto it = std::remove_if(points.begin(), points.end(),
        [&](const Pt& p) { return p.x == x && p.y == y; });
    if (it != points.end()) {
        points.erase(it, points.end());
        std::cerr << "Vector: Removed point (" << x << ", " << y << ")\n";
    } else {
        std::cerr << "Vector: Point (" << x << ", " << y << ") not found.\n";
    }
    auto end = high_resolution_clock::now();
    std::cerr << "Vector: removePoint took " << duration_cast<microseconds>(end - start).count() << " us\n";
}

void State::computeCHVector() const {
    if (points.size() < 3) {
        std::cout << "0.000000\n";
        return;
    }
    auto start = high_resolution_clock::now();
    std::vector<Pt> temp = points;
    auto hull = buildHull(temp);
    double area = polygonArea(hull);
    auto end = high_resolution_clock::now();
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << area << "\n";
    std::cerr << "Vector: computeCH took " << duration_cast<microseconds>(end - start).count() << " us\n";
}

// List variant:

void State::newGraphList(int n) {
    pointsList.clear();
    std::cerr << "List: New graph created\n";
}

void State::addPointList(double x, double y) {
    auto start = high_resolution_clock::now();
    pointsList.push_back({x, y});
    auto end = high_resolution_clock::now();
    std::cerr << "List: addPoint took " << duration_cast<microseconds>(end - start).count() << " us\n";
}

void State::removePointList(double x, double y) {
    auto start = high_resolution_clock::now();
    auto it = std::find_if(pointsList.begin(), pointsList.end(),
        [&](const Pt& p) { return p.x == x && p.y == y; });
    if (it != pointsList.end()) {
        pointsList.erase(it);
        std::cerr << "List: Removed point (" << x << ", " << y << ")\n";
    } else {
        std::cerr << "List: Point (" << x << ", " << y << ") not found.\n";
    }
    auto end = high_resolution_clock::now();
    std::cerr << "List: removePoint took " << duration_cast<microseconds>(end - start).count() << " us\n";
}

void State::computeCHList() const {
    if (pointsList.size() < 3) {
        std::cout << "0.000000\n";
        return;
    }
    auto start = high_resolution_clock::now();
    std::vector<Pt> temp(pointsList.begin(), pointsList.end());
    auto hull = buildHull(temp);
    double area = polygonArea(hull);
    auto end = high_resolution_clock::now();
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << area << "\n";
    std::cerr << "List: computeCH took " << duration_cast<microseconds>(end - start).count() << " us\n";
}
