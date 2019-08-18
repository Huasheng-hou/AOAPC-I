//
//  uva11800.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0) :x(x),y(y) {}
};

typedef Point Vector;
double EPS = 1e-6;

Vector operator + (Vector a, Vector b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }
Vector operator / (Vector a, double p) { return Vector(a.x/p, a.y/p); }

double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
double Dist(Point a, Point b) { return sqrt((a.x-b.x)*(a.x-b.x)
                                              + (a.y-b.y)*(a.y-b.y)); }
bool Parallel(Vector a, Vector b) {
    return a.x*b.y - a.y*b.x == 0;
}

int T, kase;
Point A, B, C, D;

void solve() {
    
    vector<Vector> edges;
    
    cin >> T;
    for (kase = 1; kase <= T; kase++) {
        
        edges.clear();
        
        cin >> A.x; cin >> A.y; cin >> B.x; cin >> B.y;
        cin >> C.x; cin >> C.y; cin >> D.x; cin >> D.y;
        
        edges.push_back(A-B);
        edges.push_back(A-C);
        edges.push_back(A-D);
        edges.push_back(B-C);
        edges.push_back(B-D);
        edges.push_back(C-D);
        
        int cnt[2][2], num = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = i+1; j < 6; j++) {
                Vector e1 = edges[i];
                Vector e2 = edges[j];
                
                if (Parallel(e1, e2)) {
                    cnt[num][0] = i;
                    cnt[num][1] = j;
                    num++;
                }
            }
        }
        
        cout << "Case " << kase << ": ";
        if (num == 0 || num > 2) { // Yes, num will be greater than 2
            cout << "Ordinary Quadrilateral";
        } else if (num == 1) {
            cout << "Trapezium";
        } else {
            Vector e1 = edges[cnt[0][0]];
            Vector e2 = edges[cnt[1][0]];
            
            double dist1 = Dist(Point(0, 0), e1);
            double dist2 = Dist(Point(0, 0), e2);
            if (dist1 - dist2 == 0) {
                if (Dot(e1, e2) == 0) {
                    cout << "Square";
                } else {
                    cout << "Rhombus";
                }
            } else {
                if (Dot(e1, e2) == 0) {
                    cout << "Rectangle";
                } else {
                    cout << "Parallelogram";
                }
            }
        }
        
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
