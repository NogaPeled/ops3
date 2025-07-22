#ifndef CORE_STATE_HPP
#define CORE_STATE_HPP

#include <vector>
#include <list>
#include "geom/Hull.hpp"

/**
 * @class State
 * @brief Manages a dynamic set of points and computes the convex hull area.
 *
 * Supports two implementations internally using std::vector and std::list
 * to allow profiling and comparison of data structure performance.
 */
class State {
public:
    State() = default;
    ~State() = default;

    // Vector-based methods

    /**
     * @brief Initializes a new graph with capacity for n points (vector).
     * Clears existing points and reserves space.
     * @param n Expected number of points.
     */
    void newGraphVector(int n);

    /**
     * @brief Adds a point (x,y) to the vector-based point set.
     * @param x X coordinate of the point.
     * @param y Y coordinate of the point.
     */
    void addPointVector(double x, double y);

    /**
     * @brief Removes a point (x,y) from the vector-based point set if present.
     * @param x X coordinate of the point.
     * @param y Y coordinate of the point.
     */
    void removePointVector(double x, double y);

    /**
     * @brief Computes and prints the convex hull area from the vector-based points.
     * Outputs area with 6 decimal places.
     */
    void computeCHVector() const;

    // List-based methods

    /**
     * @brief Initializes a new graph for the list-based implementation.
     * Clears existing points.
     * @param n Expected number of points (ignored for list).
     */
    void newGraphList(int n);

    /**
     * @brief Adds a point (x,y) to the list-based point set.
     * @param x X coordinate of the point.
     * @param y Y coordinate of the point.
     */
    void addPointList(double x, double y);

    /**
     * @brief Removes a point (x,y) from the list-based point set if present.
     * @param x X coordinate of the point.
     * @param y Y coordinate of the point.
     */
    void removePointList(double x, double y);

    /**
     * @brief Computes and prints the convex hull area from the list-based points.
     * Outputs area with 6 decimal places.
     */
    void computeCHList() const;

private:
    std::vector<Pt> points;      ///< Points stored in a vector for the first implementation
    std::list<Pt> pointsList;    ///< Points stored in a list for the second implementation
};

#endif // CORE_STATE_HPP
