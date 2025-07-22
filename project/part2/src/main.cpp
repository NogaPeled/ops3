#include <iostream>
#include <string>
#include "core/State.hpp"

/**
 * @brief Part 2 main driver that reads commands and applies
 *        them either to vector or list implementation of State.
 */
int main() {
    State state;
    std::string cmd;
    enum Impl { VECTOR, LIST } currentImpl = VECTOR;

    std::cout << "Choose implementation: vector or list\n";
    std::string impl;
    std::cin >> impl;
    if (impl == "list") currentImpl = LIST;
    else currentImpl = VECTOR;

    while (std::cin >> cmd) {
        if (cmd == "Newgraph") {
            int n; std::cin >> n;
            if (currentImpl == VECTOR) state.newGraphVector(n);
            else state.newGraphList(n);
        }
        else if (cmd == "Newpoint") {
            double x, y; std::cin >> x >> y;
            if (currentImpl == VECTOR) state.addPointVector(x, y);
            else state.addPointList(x, y);
        }
        else if (cmd == "Removepoint") {
            double x, y; std::cin >> x >> y;
            if (currentImpl == VECTOR) state.removePointVector(x, y);
            else state.removePointList(x, y);
        }
        else if (cmd == "CH") {
            if (currentImpl == VECTOR) state.computeCHVector();
            else state.computeCHList();
        }
        else {
            std::cerr << "Unknown command: " << cmd << "\n";
        }
    }
    return 0;
}
