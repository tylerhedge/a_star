#include <iostream>
#include <unordered_map>
#include "Viz_Graph.h"
#include <vector>
using std::cout, std::endl, std::unordered_map, std::vector;

int main() {
    vector<Point> tri;
    vector<Point> rect;
    vector<vector<Point>> polygons;
    Point start(0, 0);
    Point y(2, 2);
    Point z(4, 0);
    tri.push_back(start);
    tri.push_back(y);
    tri.push_back(z);

    Point a(6, 0);
    Point b(6, 2);
    Point c(10, 2);
    Point goal(10, 0);

    rect.push_back(a);
    rect.push_back(b);
    rect.push_back(c);
    rect.push_back(goal);
    polygons.push_back(tri);
    polygons.push_back(rect);

    VizGraph graph = constructVizGraph(polygons);
    

    vector<Point> path = graph.search(0, 1, 12, 1);

    cout << "X : Y" << endl;
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << it->x << " | " << it->y << endl;
    }
}