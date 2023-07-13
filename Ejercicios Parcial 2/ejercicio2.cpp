#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cstdio>

using namespace std;

struct Point {
    int x;
    int y;
};

double distancia(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(pow(dx,2)+pow(dy,2));
}

double DistaciaCercana(vector<Point> puntos) {
    double min = 10000000;
    for (int i = 0; i < puntos.size(); ++i) {
        for (int j = i + 1; j < puntos.size(); ++j) {
            double dist = distancia(puntos[i], puntos[j]);
            if (dist < min) {
                min = dist;
            }
        }
    }
    return min;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> puntos(n);
        for (int i = 0; i < n; i++) {
            cin >> puntos[i].x >> puntos[i].y;
        }

        double min_dist = DistaciaCercana(puntos);

        if (closestDistance < 10000) {
            printf("%.4f\n", min_dist);
        } else {
            cout << "INFINITY" << endl;
        }
    }

    return 0;
}
