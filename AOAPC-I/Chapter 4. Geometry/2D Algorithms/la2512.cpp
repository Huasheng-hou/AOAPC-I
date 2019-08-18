//
//  la2512.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/12.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// Art Gallery, Half Plane, Accepted!

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {};
    Point() {};
    friend bool operator < (Point a, Point b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Point a, double p) { return Vector(a.x*p, a.y*p); }
double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }

struct Line {
    Point P; Vector v;
    double ang;
    Line(Point p, Vector v) :P(p), v(v) { ang = atan2(v.y, v.x); };
    Line() {};
    friend bool operator < (Line L1, Line L2) { return L1.ang < L2.ang; }
};

long double PolygonArea(vector<Point> p) { // 凸包的面积
    
    long n = p.size();
    if (n <= 2) return 0;
    long double area = 0;
    for (int i = 1; i < n-1; i++) {
        area += Cross(p[i]-p[0], p[i+1]-p[0]) / 2;
    }
    
    return area;
}

bool OnLeft(Line L, Point p) {
    return Cross(L.v, p-L.P) > 0;
}

Point GetLineIntersection(Line L1, Line L2) {
    Vector w = L1.P - L2.P;
    double t = Cross(L2.v, w) / Cross(L1.v, L2.v);
    return L1.P + L1.v*t;
}

const double eps = 1e-6;

vector<Point> HalfPlaneIntersection(vector<Line> lines) {
    
    long n = lines.size();
    sort(lines.begin(), lines.end());
    
    int first, last;
    vector<Point> p(n);
    vector<Line> q(n);
    vector<Point> ans; // 结果，一个凸包 ConvexHull
    
    q[first=last=0] = lines[0];
    for (int i = 0; i < n; i++) {
        while (first < last && !OnLeft(lines[i], p[last-1])) last--;
        while (first < last && !OnLeft(lines[i], p[first])) first++;
        q[++last] = lines[i];
        
        if (fabs(Cross(q[last].v, q[last-1].v)) < eps) { // 是否添加了平行线
            last--;
            if (OnLeft(q[last], lines[i].P)) q[last] = lines[i];
        }
        if (first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]); // 保存交点
    }
    while (first < last && !OnLeft(q[first], p[last-1])) last--;
    if (last - first <= 1) return ans;
    p[last] = GetLineIntersection(q[first], q[last]);
    
    for (int i = first; i <= last; i++) ans.push_back(p[i]);
    return ans;
}

int T, N;
const int maxn = 1500 + 10;
Point p[maxn];

void solve() {

    vector<Line> lines;
//    sort(p, p+N);
    // 输入的点是顺时针，需要转化为逆时针，怎么判断？
    for (int i = 0; i < N; i++) lines.push_back(Line(p[i], p[i]-p[(i+1)%N]));
    vector<Point> convex = HalfPlaneIntersection(lines);
    
    long double area = PolygonArea(convex);
    printf("%.2Lf\n", area);
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        
        int x, y; scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d%d", &x, &y);
            p[j] = Point(x, y);
        }
        solve();
    }

    return 0;
}
