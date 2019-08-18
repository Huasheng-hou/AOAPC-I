//
//  la3218.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/13.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// uva 1340, Find the boarder! PLSG(Planar Straight-Line Graph)，卷包裹法

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {};
    Point() {};
    friend bool operator < (Point a, Point b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
    friend bool operator == (Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
};

typedef Point Vector;

struct Line {
    Point P;
    Vector v;   // 方向向量
    double ang; // 极角
    Line() {};
    Line(Point p, Vector v) :P(p), v(v) { ang = atan2(v.y, v.x); };
    friend bool operator < (Line L1, Line L2) {
        return L1.ang < L2.ang;
    }
};

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Point operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }

double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }

const int maxn = 110;
int n;
Point p[maxn]; Line e[maxn];

// 规范相交
bool IsProperIntersection(Point a1, Point b1, Point a2, Point b2) {
    
    return Cross(a2-a1, b1-a1) * Cross(b2-a1, b1-a1) < 0
    && Cross(a1-a2, b2-a2) * Cross(b1-a2, b2-a2) < 0;
}

// 线段交点
Point GetSegmentIntersection(Line a, Line b) {
    Vector w = a.P - b.P;
    double t = Cross(b.v, w) / Cross(a.v, b.v);
    return a.P + a.v*t;
}

// 卷包裹法，用O(n^2)算法
void WrappingPolygon(int u) {
    
    Point o = p[u]; Line a = e[u];
    vector<Point> p; // 交点集合
    vector<Line> q; // 交线集合
    p.push_back(o);
    
    while (true) {
    
//        for (int i = 0; )
        if (o == p[u]) break;
    }
}

void solve() {

    int u = 0, x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        p[i] = Point(x, y); u = p[i] < p[u] ? i : u;
    }
    p[n] = p[n-1];
    for (int i = 0; i < n; i++) {
        e[i] = Line(p[i], p[i+1]-p[i]);
    }
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (scanf("%d", &n)) {
        solve();
    }
    solve();

    return 0;
}
