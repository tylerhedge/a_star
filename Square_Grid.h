#pragma once

#include "A_star.h"
#include "Square_Node.h"
#include <iostream>

class SquareGrid {
    private:
    A_star<SquareNode> pathFinder;
    SquareNode** grid;
    int size;

    public:
    SquareGrid(unordered_map<SquareNode*, vector<SquareNode*>> neighbors, int size, SquareNode** grid);
    static SquareGrid create_square_grid(int size);
    vector<SquareNode*> findPath(int x1, int y1, int x2, int y2);
    ~SquareGrid();
    SquareGrid(SquareGrid& other);
    SquareGrid& operator=(SquareGrid& other);
    void removeNode(SquareNode* node);
    void removeRegion(int x1, int y1, int x2, int y2);
};