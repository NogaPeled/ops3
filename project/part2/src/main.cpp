#include <iostream>
#include <string>
#include "core/State.hpp"

/**
 * @brief Part 2 main.
 * Reads commands from stdin and performs operations on points.
 */
int main() {
    State state;
    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "Newgraph") {
            int n;
            std::cin >> n;
            state.newGraph(n);
        }
        else if (cmd == "Newpoint") {
            double x, y;
            std::cin >> x >> y;
            state.addPoint(x, y);
        }
        else if (cmd == "Removepoint") {
            double x, y;
            std::cin >> x >> y;
            state.removePoint(x, y);
        }
        else if (cmd == "CH") {
            state.computeCH();
        }
        else {
            std::cerr << "Unknown command: " << cmd << "\n";
        }
    }
    return 0;
}
