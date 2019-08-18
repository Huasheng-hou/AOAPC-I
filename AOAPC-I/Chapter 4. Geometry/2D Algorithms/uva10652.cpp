//
//  uva10652.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

// Board Wraping, Accepted!

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {};
    Point() {};
    friend bool operator < (Point a, Point b) {
        if (a.x < b.x) return true;
        if (a.x == b.x) return a.y < b.y;
        return false;
    }
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(b.x-a.x, b.y-a.y); }
Vector operator + (Point a, Point b) { return Vector(b.x+a.x, b.y+a.y); }
bool operator == (Point a, Point b) { return a.x==b.x && a.y==b.y; }

long double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
Vector Rotate(Vector a, double r) { return Vector(a.x*cos(r)-a.y*sin(r),
                                                  a.x*sin(r)+a.y*cos(r)); }

double PolygonArea(int n, Point *p) {
    
    double ans = 0;
    for (int i = 1; i <= n-2; i++) {
        ans += Cross(p[i]-p[0], p[i+1]-p[0]); // 注意精度
    }
    return ans / 2;
}

const int maxn = 2400+10;
int N, n;
double area;

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

void solve() {
    
    scanf("%d", &n);
    double x, y, w, h, phi;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &h, &phi);
        
        phi = -phi / 180 * acos(-1.0);
        Point center = Point(x, y);
        
        p[4*i] = Rotate(Vector(-w/2, -h/2), phi) + center;
        p[4*i+1] = Rotate(Vector(-w/2, h/2), phi) + center;
        p[4*i+2] = Rotate(Vector(w/2, -h/2), phi) + center;
        p[4*i+3] = Rotate(Vector(w/2, h/2), phi) + center;
        
        area += w*h;
    }
    
    n *= 4;
    sort(p, p+n);
    int m = ConvexHull();
    
    double mould = PolygonArea(m, e);
    
    printf("%.1lf %%\n", area * 100 / mould);
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        area = 0;
        solve();
    }
    
    return 0;
}
