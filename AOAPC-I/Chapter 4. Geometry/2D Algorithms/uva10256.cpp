//
//  uva10256.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std; // Accepted!

struct Point {
  
    int x, y;
    Point(int x, int y) :x(x), y(y) {};
    Point() {};
    friend bool operator < (Point a, Point b) {
        if (a.x < b.x) return true;
        if (a.x == b.x) return a.y < b.y;
        return false;
    }
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(b.x-a.x, b.y-a.y); }
bool operator == (Point a, Point b) { return a.x==b.x && a.y==b.y; }

long long Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long long Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }

const int maxN = 500+2;

int M, C;
Point Maj[maxN], Cle[maxN];
Point edges[maxN], edges2[maxN];

// * 点在线段上
bool OnSegment(Point p, Point a1, Point a2) {
    return Cross(p-a1, a1-a2) == 0 && Dot(a1-p, a2-p) < 0;
}

// * 线段相交
bool Intersection(Point a1, Point a2, Point b1, Point b2) {
    long long c1 = Cross(a1-b1, b2-b1); long long c2 = Cross(a2-b1, b2-b1);
    long long c3 = Cross(b1-a1, a2-a1); long long c4 = Cross(b2-a1, a2-a1);
    return c1*c2 < 0 && c3*c4 < 0;
}

// * 点在多变形内
int isPointInPolygon(Point p, int n, Point *poly) {
    
    int wn = 0;
    for (int i = 0; i < n; i++) {
        if (p == poly[i] || p == poly[(i+1)%n]) return -1;
        if (OnSegment(p, poly[i], poly[(i+1)%n])) return -1; // 在边界上
        long long k = Cross(poly[(i+1)%n]-poly[i], p-poly[i]);
        int d1 = poly[i].y - p.y;
        int d2 = poly[(i+1)%n].y - p.y;
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1; //内部
    return 0; //外部
}

bool ConvexPolygonDisjoint(int m, int n) {
    
    for (int i = 0; i < m; i++)
        if (isPointInPolygon(edges[i], n, edges2) != 0) return false;
    for (int i = 0; i < n; i++)
        if (isPointInPolygon(edges2[i], m, edges) != 0) return false;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (Intersection(edges[i], edges[(i+1)%m], edges2[j], edges2[(j+1)%n]))
                return false;
    return true;
}

// * 求凸包，须熟记
int ConvexHull(Point *p, int n, Point *edges) {
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && Cross(edges[m-1]-edges[m-2], p[i]-edges[m-2]) <= 0) {
            m--;
        }
        edges[m++] = p[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--) {
        while (m > k && Cross(edges[m-1]-edges[m-2], p[i]-edges[m-2]) <= 0) {
            m--;
        }
        edges[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}

void solve() {
    
    int x, y;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &x, &y); Maj[i].x = x; Maj[i].y = y;
    }
    for (int i = 0; i < C; i++) {
        scanf("%d%d", &x, &y); Cle[i].x = x; Cle[i].y = y;
    }
    
    sort(Maj, Maj+M); sort(Cle, Cle+C);
    
    int m = ConvexHull(Maj, M, edges);
    int n = ConvexHull(Cle, C, edges2);
    
    bool have = ConvexPolygonDisjoint(m, n);
    
    if (!have) printf("No\n");
    if (have) printf("Yes\n");
}

int main() {
 
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (scanf("%d%d", &M, &C) == 2 && M > 0 && C > 0) {
        solve();
    }
    
    return 0;
}
