//
//  la4992.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// Jungle Post ，丛林瞭望台 Accepted!

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) :x(x), y(y) {};
    Point() {};
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

bool onLeft(Line L, Point p) {
    return Cross(L.v, p-L.P) > 0;
}

// 有向直线交点
Point GetLineIntersection(Line a, Line b) {
    Vector w = a.P - b.P;
    double t = Cross(b.v, w) / Cross(a.v, b.v);
    return a.P + a.v*t;
}

const double eps = 1e-6;

// 半平面交主过程
vector<Point> HalfplaneIntersection(vector<Line>& L) {
    
    int n = (int)L.size();
    sort(L.begin(), L.end()); // 按极角排序
    
    int first, last;
    vector<Point> p(n);
    vector<Line> q(n);  // 双端队列
    vector<Point> ans;
    
    q[first=last=0] = L[0];
    for (int i = 1; i < n; i++) {
        while (first < last && !onLeft(L[i], p[last-1])) last--;
        while (first < last && !onLeft(L[i], p[first])) first--;
        q[++last] = L[i];
        
        if (fabs(Cross(q[last].v, q[last-1].v)) < eps) {
            last--;
            if (onLeft(q[last], L[i].P)) q[last] = L[i];
        }
        if (first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]);
    }
    while (first < last && !onLeft(q[first], p[last-1])) last--; // 删除无用平面
    if (last - first <= 1) return ans;
    p[last] = GetLineIntersection(q[last], q[first]);
    
    for (int i = first; i <= last; i++) ans.push_back(p[i]); // 结果是一个凸集？
    return ans;
}

const int maxn = 50000+10;
int n;
Point p[maxn];

bool check(int m) {
    
    vector<Line> lines;
    for (int i = 0; i < n; i++) {
        lines.push_back(Line(p[i], p[i]-p[(i+m+1)%n]));
    }
    return HalfplaneIntersection(lines).empty();
}

void solve() {

    if (n == 3) { cout << 1; return; }
    int L = 1, R = n-2, M;
    while (L < R) {
        M = (R+L) / 2;
        if (!check(M)) {
            L = M+1;
        } else {
            R = M;
        }
    }
    cout << L;
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (cin >> n && n > 0) {
     
        int x, y;
        for (int i = 0; i < n; i++) {
            
            cin >> x >> y; p[i] = Point(x, y);
        }
        solve();
        cout << "\n";
    }
    
    return 0;
}
