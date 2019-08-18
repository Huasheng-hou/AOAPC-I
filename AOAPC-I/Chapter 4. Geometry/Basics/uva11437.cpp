//
//  uva11437.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "math.h"

// * triangle fun;

using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0) :x(x),y(y) {}
};

typedef Point Vector;

Vector operator + (Vector a, Vector b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }
Vector operator / (Vector a, double p) { return Vector(a.x/p, a.y/p); }

double Cross(Vector a, Vector b) { return a.x*b.y - a.y * b.x; }

static int T;
static Point A, B, C, D, E, F, P, Q, R;

Point getLineIntersection(Point P, Vector v, Point Q, Vector w) {
    
    Vector u = P-Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

static void solve() {
    
    cin >> T;
    while (T--) {
        
        cin >> A.x >> A.y; cin >> B.x >> B.y; cin >> C.x >> C.y;
    
        D = B + (C-B) / 3;
        E = C + (A-C) / 3;
        F = A + (B-A) / 3;
        
        P = getLineIntersection(A, D-A, B, E-B);
        Q = getLineIntersection(C, F-C, B, E-B);
        R = getLineIntersection(A, D-A, C, F-C);
        
        long area = round(fabs(Cross(Q-P, R-P) / 2));
        cout << area;
        cout << "\n";
    }
}

int main() {
    
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
    
    solve();
    
    return 0;
}
