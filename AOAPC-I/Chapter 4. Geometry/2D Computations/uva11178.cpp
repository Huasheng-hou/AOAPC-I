//
//  uva11178.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    long double x, y;
    Point(long double x, long double y) :x(x), y(y) {};
    Point() {};
};

typedef Point Vector;

Vector operator - (Point a, Point b) { return Vector(a.x-b.x, a.y-b.y); }
Vector operator + (Point a, Point b) { return Vector(a.x+b.x, a.y+b.y); }
Vector operator * (Vector a, long double p) { return Vector(a.x*p, a.y*p); }

// * 旋转，单位取弧度
Vector Rotate(Vector v, double a) { return Vector(v.x*cos(a)-v.y*sin(a),
                                                  v.x*sin(a)+v.y*cos(a)); }
long double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
long double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
long double Length(Vector a) { return sqrtl(Dot(a, a)); }
long double Angle(Vector a, Vector b) { return acosl(Dot(a, b) / Length(a) / Length(b)); }

int N;

// * 直线交点公式，须熟记
Point getInterSection(Vector v1, Point a, Vector v2, Point b) {
    
    Vector u = a-b;
    long double t = Cross(v2, u) / Cross(v1, v2);
    return a + v1*t;
}

Point getD(Point a, Point b, Point c) {
    
    Vector v1 = b-a, v2 = c-a, v3 = a-b, v4 = c-b;
    long double alpha = Angle(v1, v2);
    long double beta = Angle(v4, v3);
    
    if (Cross(v1, v2) > 0) { // * 注意判断旋转方向
        v1 = Rotate(v1, alpha/3);
    } else {
        v1 = Rotate(v1, -alpha/3);
    }
    if (Cross(v3, v4) > 0) {
        v3 = Rotate(v3, beta/3);
    } else {
        v3 = Rotate(v3, -beta/3);
    }
    
    return getInterSection(v1, a, v3, b);
}

void solve() {
    int x, y; Point A, B, C, D, E, F;
    
    scanf("%d%d", &x, &y); A = Point(x, y);
    scanf("%d%d", &x, &y); B = Point(x, y);
    scanf("%d%d", &x, &y); C = Point(x, y);
    
    D = getD(B, C, A);
    E = getD(C, A, B);
    F = getD(A, B, C);
    
    printf("%.6Lf %.6Lf ", D.x, D.y);
    printf("%.6Lf %.6Lf ", E.x, E.y);
    printf("%.6Lf %.6Lf", F.x, F.y);
    printf("\n");
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        solve();
    }
    
    return 0;
}
