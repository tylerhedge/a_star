#include <iostream>
#include <unordered_map>
#include "Square_Grid.h"
#include <vector>
using std::cout, std::endl, std::unordered_map, std::vector;

int main() {
    SquareGrid grid = SquareGrid::create_square_grid(10);
    grid.removeRegion(1, 0, 6, 6);
    vector<SquareNode*> path = grid.findPath(0, 0, 9, 0);
    cout << "X : Y" << endl;
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << (*it)->x << " | " << (*it)->y << endl;
    }
}