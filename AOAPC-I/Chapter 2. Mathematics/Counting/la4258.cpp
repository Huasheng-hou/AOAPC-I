//
//  la4258.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/16.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// 

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) :x(x), y(y) {};
    friend bool operator < (Point a, Point b) { return a.x < b.x; }
    Point() {};
};

const int maxn = 60;
int T, n;
Point p[maxn];

void solve() {

    cin >> n; int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; p[i] = Point(x, y);
    }
    
    sort(p, p+n);
    cout << "tt!";
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    cin >> T;
    while (T--) solve();

    return 0;
}
