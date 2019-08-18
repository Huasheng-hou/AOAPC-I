//
//  la3890.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// uva 1396, Distant point from the sea. Accepted!

using namespace std;

struct Point {
    long double x, y;
    Point(long double x, long double y) :x(x), y(y) {}
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
Vector operator * (Point a, long double p) { return Vector(a.x*p, a.y*p); }
Vector operator / (Point a, long double p) { return Vector(a.x/p, a.y/p); }

long double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
long double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }
Vector Rotate(Vector a, long double r) { return Vector(a.x*cos(r)-a.y*sin(r),
                                                       a.x*sin(r)+a.y*cos(r)); }
Vector Normal(const Vector& A) { long double L = Length(A); return Vector(-A.y/L, A.x/L); }

struct Line {
    Point p; Vector v;
    long double ang;
    Line() {};
    Line(Point p, Vector v) :p(p), v(v) { ang = atan2(v.y, v.x); };
    friend bool operator < (Line l1, Line l2) { return l1.ang < l2.ang; }
};

const int maxn = 110, maxd = 20000;
const long double eps = 1e-8;
int n;
Point p[maxn]; Line e[maxn];

void ShiftLine(Line &L, long double d) { // 结构体在传参时会copy，需要传地址
    Point a = L.p + Rotate(L.v, M_PI_2)*(d/Length(L.v));
    L.p.x = a.x; L.p.y = a.y;
}

bool OnLeft(Line L, Point p) { return Cross(p-L.p, L.v) <= 0; }

Point GetLineIntersection(Line e1, Line e2) {
    Vector w = e1.p - e2.p;
    long double t = Cross(e2.v, w) / Cross(e1.v, e2.v);
    return e1.p + e1.v*t;
}

vector<Point>HalfPlaneIntersection(int n) {

    int first, last;
    
    vector<Point> p(n); // 直线交点
    vector<Line> q(n);  // 双端队列 ？
    vector<Point> ans;
    
    q[first=last=0] = e[0];
    for (int i = 1; i < n; i++) { // 0已经初始化，从第1个开始
        while (last > first && !OnLeft(e[i], p[last-1])) last--;
        while (last > first && !OnLeft(e[i], p[first])) first++;
        q[++last] = e[i];
        if (fabsl(Cross(q[last].v, q[last-1].v)) < eps) {
            last--;
            if (OnLeft(q[last], e[i].p)) q[last] = e[i];
        }
        if (first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]);
    }
    while (first < last && !OnLeft(q[first], p[last-1])) last--;
    if (last - first <= 1) return ans;
    p[last] = GetLineIntersection(q[last], q[first]);
    
    // 复制结果
    for (int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}

long double Bisection() {
    
    long double left = 0; long double right = maxd;
    long double middle;
    
    while (right - left >= eps) {
        
        middle = (left + right) / 2.;
        for (int i = 0; i < n; i++)
            ShiftLine(e[i], middle);
        
        if (!HalfPlaneIntersection(n).empty()) {
            left = middle;
        } else {
            right = middle;
        }
        
        for (int i = 0; i < n; i++)
            ShiftLine(e[i], -middle);
    }
    return right;
}

void solve() {

    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y); p[i] = Point(x, y);
    }
    for (int i = 0; i < n; i++) {
        e[i] = Line(p[i], p[(i+1)%n]-p[i]);
    }
    sort(e, e+n);
    
    long double ans = Bisection();
    printf("%.6Lf\n", ans);
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (scanf("%d", &n) == 1 && n > 0) {
        solve();
    }
    return 0;
}
