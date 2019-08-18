//
//  uva11168.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) :x(x), y(y) {}
    friend bool operator < (Point a, Point b) {
        if (a.x < b.x) return true;
        if (a.x == b.x) return a.y < b.y;
        return false;
    }
    Point() {}
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }

long long Dot(Vector a, Vector b) { return (long long)a.x*b.x + (long long)a.y*b.y; }
long long Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }

const int maxn = 10000+2;
const double INF = 1<<30;

int N, n, kase, sumX, sumY;
Point houses[maxn];
Vector edges[maxn];

long double DistanceToEdge(Vector e, Point a) {
    
    Vector normal = Vector(-e.y, e.x); // * 获取法向量
    long double C = -Dot(normal, a) * n; // * 构造一般式
    long double dist = Dot(Vector(sumX, sumY), normal) + C;
    
    long double ret = fabsl(dist) / Length(normal);
    return ret;
}

int ConvexHull() {
    
    int m = 0;
    for (int i = 0; i < n; i++) {
        
        while (m > 1 && Cross(edges[m-1]-edges[m-2], houses[i]-edges[m-2]) <= 0) {
            m--;
        }
        edges[m++] = houses[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--) {
        
        while (m > k && Cross(edges[m-1]-edges[m-2], houses[i]-edges[m-2]) <= 0) {
            m--;
        }
        edges[m++] = houses[i];
    }
    if (n>1) m--;
    return m;
}

void solve() {
    
    scanf("%d", &N);
    for (kase = 1; kase <= N; kase++) {
        
        sumX = 0; sumY = 0;
        
        scanf("%d", &n);
        
        int x, y;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            sumX += x; sumY += y;
            houses[i].x = x; houses[i].y = y;
        }
        
        sort(houses, houses+n);
        int m = ConvexHull();
        
        long double dist = INF;
        if (n == 1) {
            dist = 0;
            printf("Case #%d: %.3Lf\n", kase, dist / n);
            continue;
        }
        for (int i = 0; i < m-1; i++) {
            long double tmp = DistanceToEdge(edges[i+1]-edges[i], edges[i]);
            dist = fminl(dist, tmp);
        }
        dist = fminl(dist, DistanceToEdge(edges[m-1]-edges[0], edges[0]));
        
        printf("Case #%d: %.3Lf\n", kase, dist / n);
    }
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    solve();
    
    return 0;
}
