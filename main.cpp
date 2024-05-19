#include <iostream>
#include <unordered_map>
#include "Viz_Graph.h"
#include <vector>
#include "plotter.h"
using std::cout, std::endl, std::unordered_map, std::vector;

int main() {
    vector<vector<Point>> polygons;
    vector<Point> wall;
    wall.push_back(Point(5, 0));
    wall.push_back(Point(5, 5));
    wall.push_back(Point(6, 5));
    wall.push_back(Point(6, 0));

    vector<Point> railing;
    railing.push_back(Point(9, 3));
    railing.push_back(Point(9, 9));
    railing.push_back(Point(13, 9));
    railing.push_back(Point(20, 5));
    railing.push_back(Point(18, 5));
    railing.push_back(Point(13, 7));
    railing.push_back(Point(11, 8));
    railing.push_back(Point(11, 3));

    vector<Point> wierd_c;
    wierd_c.push_back(Point(30, 8));
    wierd_c.push_back(Point(25, 13));
    wierd_c.push_back(Point(25, 18));
    wierd_c.push_back(Point(35, 33));
    wierd_c.push_back(Point(38, 30));
    wierd_c.push_back(Point(28, 15));
    wierd_c.push_back(Point(28, 15));
    wierd_c.push_back(Point(33, 10));



    polygons.push_back(wall);
    polygons.push_back(railing);
    polygons.push_back(wierd_c);


    VizGraph graph = constructVizGraph(polygons);
    

    vector<Point> path = graph.search(0, 0, 30, 17);

    cout << "X : Y" << endl;
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << it->x << " | " << it->y << endl;
    }

    plot(path, polygons);
}