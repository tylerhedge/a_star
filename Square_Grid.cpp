
#include "Square_Grid.h"
#include <cmath>

using std::abs;

SquareGrid::SquareGrid(unordered_map<SquareNode*, vector<SquareNode*>> neighbors, int size, SquareNode** grid)
 : pathFinder(
    neighbors,
    [](SquareNode* a, SquareNode* b) -> double {
        return abs(a->x - b->x) + abs(a->y - b->y);
    },
    [](SquareNode* a, SquareNode* b) -> double {
        return abs(a->x - b->x) + abs(a->y - b->y);
    }
    ), grid(grid), size(size) {}

 SquareGrid SquareGrid::create_square_grid(int size) {
    SquareNode** grid = new SquareNode*[size];
    unordered_map<SquareNode*, vector<SquareNode*>> neighbors;
    for (int i = 0; i < size; i++) {
        grid[i] = new SquareNode[size];
        for (int j = 0; j < size; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            neighbors[&grid[i][j]] = {};

            // Add neighboring nodes (4-connectivity)
            if (i > 0) neighbors[&grid[i][j]].push_back(&grid[i - 1][j]); // Up
            if (i < size - 1) neighbors[&grid[i][j]].push_back(&grid[i + 1][j]); // Down
            if (j > 0) neighbors[&grid[i][j]].push_back(&grid[i][j - 1]); // Left
            if (j < size - 1) neighbors[&grid[i][j]].push_back(&grid[i][j + 1]); // Right

        }
    }

    return SquareGrid(neighbors, size, grid);
}

vector<SquareNode*> SquareGrid::findPath(int x1, int y1, int x2, int y2) {
    return pathFinder.search(&grid[y1][x1], &grid[y2][x2]);
}

SquareGrid::~SquareGrid() {
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

SquareGrid::SquareGrid(SquareGrid& other) : pathFinder(other.pathFinder), grid(nullptr), size(other.size) {
    for (int i = 0; i < size; i++) {
        grid[i] = new SquareNode[size];
        for (int j = 0; j < size; j++) {
            grid[i][j].x = other.grid[i][j].x;
            grid[i][j].y = other.grid[i][j].y;
        }
    }
}

SquareGrid& SquareGrid::operator=(SquareGrid& other) {
    if (this != &other) {
        if (grid != nullptr) {
                for (int i = 0; i < size; i++) {
                delete[] grid[i];
            }
            delete[] grid;
            grid = nullptr;
        }
        pathFinder = other.pathFinder;
        size = other.size;
        for (int i = 0; i < size; i++) {
            grid[i] = new SquareNode[size];
            for (int j = 0; j < size; j++) {
                grid[i][j].x = other.grid[i][j].x;
                grid[i][j].y = other.grid[i][j].y;
            }
        }
    }
    return *this;
}

void SquareGrid::removeNode(SquareNode* node) {
    for (auto it = pathFinder.neighbors[node].begin(); it != pathFinder.neighbors[node].end(); it++) {
        for (auto jt = pathFinder.neighbors[*it].begin(); jt != pathFinder.neighbors[*it].end(); jt++) {
            if (*jt == *it) pathFinder.neighbors[*it].erase(jt);
        }
    }
    pathFinder.neighbors[node].clear();
}
void SquareGrid::removeRegion(int x1, int y1, int x2, int y2) {
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            removeNode(&grid[i][j]);
        }
    }
}

