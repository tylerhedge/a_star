#include <iostream>
#include <unordered_map>
#include "Viz_Graph.h"
#include <vector>
#include "plotter.h"
#include "prioQueue.h"
using std::cout, std::endl, std::unordered_map, std::vector;

int main() {
    // vector<Point> top = 
    // {
    //     Point(0, 5),
    //     Point(1, 5),
    //     Point(1, 4),
    //     Point(1.25, 4),
    //     Point(1.25, 5),
    //     Point(5, 5),
    //     Point(5, 4),
    //     Point(4, 4),
    //     Point(4, 3.25),
    //     Point(5, 3.25),
    //     Point(5, 3),
    //     Point(3, 3),
    //     Point(3, 4),
    //     Point(2, 4),
    //     Point(2, 3),
    //     Point(1.5, 3),
    //     Point(1.5, 2.25),
    //     Point(2, 2.25),
    //     Point(2, 1),
    //     Point(2.25, 1),
    //     Point(2.25, 3.75),
    //     Point(2.75, 3.75),
    //     Point(2.75, 2.75),
    //     Point(4, 2.75),
    //     Point(4, 1.75),
    //     Point(4.25, 1.75),
    //     Point(4.25, 2.75),
    //     Point(5, 2.75),
    //     Point(5, 1),
    //     Point(5.25, 1),
    //     Point(5.25, 5.25),
    //     Point(0, 5.25)
    // };

    // vector<Point> bottom = {
    //     Point(0, 4),
    //     Point(0, 0),
    //     Point(5.25, 0),
    //     Point(5.25, 0.25),
    //     Point(3.25, 0.25),
    //     Point(3.25, 1),
    //     Point(4.25, 1),
    //     Point(4.25, 1.25),
    //     Point(3.25, 1.25),
    //     Point(3.25, 2.25),
    //     Point(3, 2.25),
    //     Point(3, 0.25),
    //     Point(0.25, 0.25),
    //     Point(0.25, 2),
    //     Point(0.75, 2),
    //     Point(0.75, 1),
    //     Point(1, 1),
    //     Point(1, 2.25),
    //     Point(0.25, 2.25),
    //     Point(0.25, 4)
    // };
    // 15 inches assumed radius = 0.381 meters
    double radius = 0.381;
    vector<Point> redWallHor = {
        Point(0, 3.05 - radius),
        Point(1.625 + radius, 3.05 - radius),
        Point(1.625 + radius, 3.074 + radius),
        Point(0, 3.074 + radius)
    };

    vector<Point> redWallVert = {
        Point(3.079 - radius, 0),
        Point(3.079 - radius, 1.625 + radius),
        Point(3.079 + radius, 1.625 + radius),
        Point(3.079 + radius, 0)
    };

    vector<Point> redDoohickey = {
        Point(1 - radius, 1 - radius),
        Point(1 - radius, 2 + radius),
        Point(2 + radius, 2 + radius),
        Point(2 + radius, 1 - radius)
    };

    vector<Point> centerLeftWall = {
        Point(4.5 - radius, 2.8 - radius),
        Point(4.5 - radius, 6 + radius),
        Point(4.5 + radius, 6 + radius),
        Point(4.5 + radius, 2.8 - radius)
    };

    vector<Point> blueWallHor = {
        Point(12 - 0, 8 - (3.05 - radius)),
        Point(12 - (1.625 + radius), 8 - (3.05 - radius)),
        Point(12 - (1.625 + radius), 8 - (3.074 + radius)),
        Point(12 - 0, 8 - (3.074 + radius))
    };

    vector<Point> blueWallVert = {
        Point(12 - (3.079 - radius), 8 - 0),
        Point(12 - (3.079 - radius), 8 - (1.625 + radius)),
        Point(12 - (3.079 + radius), 8 - (1.625 + radius)),
        Point(12 - (3.079 + radius), 8 - 0)
    };

    vector<Point> blueDoohickey = {
        Point(12 - (1 - radius), 8 - (1 - radius)),
        Point(12 -(1 - radius), 8 - (2 + radius)),
        Point(12 -(2 + radius), 8 - (2 + radius)),
        Point(12 - (2 + radius), 8 - (1 - radius))
    };

    vector<Point> centerRightWall = {
        Point(12 - (4.5 - radius), 8 - (2.8 - radius)),
        Point(12 - (4.5 - radius), 8 - (6 + radius)),
        Point(12 - (4.5 + radius), 8 - (6 + radius)),
        Point(12 - (4.5 + radius), 8 - (2.8 - radius))
    };
    
    vector<vector<Point>> polygons = {
        redWallHor,
        redWallVert,
        redDoohickey,
        centerLeftWall,
        blueWallHor,
        blueWallVert,
        blueDoohickey,
        centerRightWall
    };


    
    VizGraph graph = constructVizGraph(polygons);
    

    vector<Point> path = graph.search(0.5, 0.5, 3, 3);

    cout << "X : Y" << endl;
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << it->x << " | " << it->y << endl;
    }

    plot(path, polygons);
}