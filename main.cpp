#include <iostream>
#include <unordered_map>
#include "Viz_Graph.h"
#include <vector>
#include "plotter.h"
#include "prioQueue.h"
using std::cout, std::endl, std::unordered_map, std::vector;

int main() {
    vector<vector<Point>> polygons;
    vector<Point> top = 
    {
        Point(0, 5),
        Point(1, 5),
        Point(1, 4),
        Point(1.25, 4),
        Point(1.25, 5),
        Point(5, 5),
        Point(5, 4),
        Point(4, 4),
        Point(4, 3.25),
        Point(5, 3.25),
        Point(5, 3),
        Point(3, 3),
        Point(3, 4),
        Point(2, 4),
        Point(2, 3),
        Point(1.5, 3),
        Point(1.5, 2.25),
        Point(2, 2.25),
        Point(2, 1),
        Point(2.25, 1),
        Point(2.25, 3.75),
        Point(2.75, 3.75),
        Point(2.75, 2.75),
        Point(4, 2.75),
        Point(4, 1.75),
        Point(4.25, 1.75),
        Point(4.25, 2.75),
        Point(5, 2.75),
        Point(5, 1),
        Point(5.25, 1),
        Point(5.25, 5.25),
        Point(0, 5.25)
    };

    vector<Point> bottom = {
        Point(0, 4),
        Point(0, 0),
        Point(5.25, 0),
        Point(5.25, 0.25),
        Point(3.25, 0.25),
        Point(3.25, 1),
        Point(4.25, 1),
        Point(4.25, 1.25),
        Point(3.25, 1.25),
        Point(3.25, 2.25),
        Point(3, 2.25),
        Point(3, 0.25),
        Point(0.25, 0.25),
        Point(0.25, 2),
        Point(0.75, 2),
        Point(0.75, 1),
        Point(1, 1),
        Point(1, 2.25),
        Point(0.25, 2.25),
        Point(0.25, 4)
    };

    polygons.push_back(top);
    polygons.push_back(bottom);
    VizGraph graph = constructVizGraph(polygons);
    

    vector<Point> path = graph.search(4.5, 3.1, 6, 0.5);

    cout << "X : Y" << endl;
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << it->x << " | " << it->y << endl;
    }

    plot(path, polygons);
}