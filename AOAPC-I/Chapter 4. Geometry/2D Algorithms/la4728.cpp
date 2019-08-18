//
//  la4728.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/13.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

// uva 1453 Squares, Antipodals（对踵点）Accepted!

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {}
    Point() {}
    friend bool operator < (Point a, Point b) {
        if (a.x < b.x) return true;
        if (a.x == b.x) return a.y < b.y;
        return false;
    }
    friend bool operator == (Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Point a, double p) { return Vector(a.x*p, a.y*p); }

long double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
long double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }

const int maxn = 400000+10;
int T, n;
Point p[maxn], e[maxn];

int ConvexHull() {
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(e[m-1]-e[m-2], p[i]-e[m-2]) <= 0) m--;
        e[m++] = p[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--) {
        while (m > k && Cross(e[m-1]-e[m-2], p[i]-e[m-2]) <= 0) m--;
        e[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}

long long Diameter(int m) {
    
    long long d = 0;
    for (int u = 0, v = 1; u < m; u++) {
        
        while (true) { // 当取到的Area变小时停止旋转
            long long diff = Cross(e[(u+1)%m]-e[u], e[(v+1)%m]-e[v]);
            if (diff <= 0) {
                d = fmaxl(d, Dot(e[u]-e[v], e[u]-e[v]));
                if (d == 0) d = fmaxl(d, Dot(e[u]-e[v+1], e[u]-e[v+1]));
                break;
            }
            v = (v+1)%m;
        }
    }
    return d;
}

void solve() {

    cin >> n;
    
    int x, y, w;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> w;
        p[4*i] = Point(x, y); p[4*i+1] = Point(x, y+w);
        p[4*i+2] = Point(x+w, y); p[4*i+3] = Point(x+w, y+w);
    }
    
    n *= 4;
    sort(p, p+n);
    n = (int)(unique(p, p+n) - p);
    int m = ConvexHull();
    
    cout << Diameter(m) << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
