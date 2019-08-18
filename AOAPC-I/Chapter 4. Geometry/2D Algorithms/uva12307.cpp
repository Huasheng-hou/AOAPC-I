//
//  uva12307.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/13.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

// Smallest Enclosing Rectangle

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {}
    friend bool operator < (Point a, Point b) {
        if (a.x < b.x) return true;
        if (a.x == b.x) return a.y < b.y;
        return false;
    }
    Point() {}
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Point a, double p) { return Vector(a.x*p, a.y*p); }

long double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
long double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }
//long double Length(Vector a) { return sqrtl(Dot(a, a)); }s

long double DistanceToLine(Point o, Vector v, Point p) {
    
    return 0;
}

void solve() {

    
    
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    solve();

    return 0;
}
