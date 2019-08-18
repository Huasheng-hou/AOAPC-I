//
//  la2453.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/12.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// uva 1303 Wall，处理圆的切线，取凸壳周长和圆周之和即可 Wrong Answer?

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) :x(x), y(y) {};
    Point() {};
    friend bool operator < (Point a, Point b) {
        if (a.x != b.y) return a.x < b.x;
        return a.y < b.y;
    }
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Point a, double p) { return Vector(a.x*p, a.y*p); }
long Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
long Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }
long double Angle(Vector a, Vector b) { return acosl(Cross(a, b) / Length(a) / Length(b)); }

const int maxn = 1000+10;
int T, N, L;
Point p[maxn], e[maxn]; // Convex Hull

int ConvexHull() {
    
    int m = 0;
    for (int i = 0; i < N; i++) {
        while (m > 1 && Cross(e[m-1]-e[m-2], p[i]-e[m-2]) <= 0) m--;
        e[m++] = p[i];
    }
    int k = m;
    for (int i = N-2; i >= 0; i--) {
        while (m > k && Cross(e[m-1]-e[m-2], p[i]-e[m-2]) <= 0) m--;
        e[m++] = p[i];
    }
    if (N > 1) m--;
    return m;
}

void GetLength(int m) {
    
    long double length = 0;
    for (int i = 0; i < m; i++) length += Length(e[(i+1)%m] - e[i]);
    length += 2*M_PI*L;
    
    printf("%.0Lf\n", length);
}

void solve() {

    cin >> T;
    while (T--) {
        cin >> N >> L;
        int x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            p[i] = Point(x, y);
        }
        
        sort(p, p+N);
        int m = ConvexHull();
        GetLength(m);
        if (T) printf("\n");
    }
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    solve();

    return 0;
}
