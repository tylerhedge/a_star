#include <vector>
#include "Point.h"
#include <fstream>
#include "plotter.h"

using std::vector;
void plot(vector<Point> path, vector<vector<Point>> polygons) {
    std::ofstream outFile("graph.txt");
    outFile << path.front().x << "_" <<  path.front().y << '\n';
    outFile << path.back().x << "_" << path.back().y << '\n';
    for (auto it = polygons.begin(); it != polygons.end(); it++) {
        for (auto jt = it->begin(); jt != it->end(); jt++) {
            outFile << jt->x << "_" << jt->y << " ";
        }
        outFile << '\n';
    }
    outFile << "PATH\n";

    for (auto it = path.begin(); it != path.end(); it++) {
        outFile << it->x << "_" << it->y << '\n';
    }
    outFile.close();
}