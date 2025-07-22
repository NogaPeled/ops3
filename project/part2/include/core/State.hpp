#pragma once
#include <vector>
#include "geom/Point.hpp"

/**
 * @class State
 * @brief Manages a dynamic set of points and convex hull computations.
 */
class State {
private:
    std::vector<Pt> points; ///< Current set of points.

public:
    void newGraph(int n);
    void addPoint(double x, double y);
    void removePoint(double x, double y);
    void computeCH() const;
};
