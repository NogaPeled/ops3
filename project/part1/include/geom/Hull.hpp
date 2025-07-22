#pragma once
#include <vector>
#include "Point.hpp"

/**
 * @brief Builds the convex hull of a set of 2D points.
 * @param pts Vector of points (may be reordered during processing).
 * @return Convex hull points in counter-clockwise order.
 */
std::vector<Pt> buildHull(std::vector<Pt>& pts);

/**
 * @brief Computes the area of a polygon using the Shoelace formula.
 * @param poly Vector of polygon points in order.
 * @return Area of the polygon.
 */
double polygonArea(const std::vector<Pt>& poly);
