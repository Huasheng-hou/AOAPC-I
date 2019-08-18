//
//  la4064.cpp
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

// 直角或锐角三角形个数，容斥原理

using namespace std;

typedef unsigned long long ull;

const int maxn = 1210;
int n, kase = 0;
double x[maxn], y[maxn], r[maxn];

ull count(int k) {
    
    if (n < 3) return 0;
    vector<long double>angle;
    for (int i = 0; i < n; i++) {
        if (i != k) angle.push_back(atan2l((long double)(y[i]-y[k]),
                                           (long double)(x[i]-x[k])));
    }
    
    sort(angle.begin(), angle.end());
    
    int t1 = 1, t2 = 1, m = n-1;
    ull c = 0;
    for (int i = 0; i < m; i++) {
        
        while (t1 < m) {
            long double delta = angle[(i+t1)%m] - angle[i];
            if (delta < 0) delta += 2*M_PI;
            if (delta > M_PI_2) break;
            t1++;
        }
        t2 = t1;
        while (t2 < m) {
            long double delta = angle[(i+t2)%m] - angle[i];
            if (delta < 0) delta += 2*M_PI;
            if (delta > M_PI) break;
            t2++;
        }
        if (t2 > t1) c+= t2-t1;
        t1--;
    }
    
    return c;
}

void solve() {

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    unsigned long long ans = (ull)n * (ull)(n-1) / 2 * (ull)(n-2) / 3;
    for (int i = 0; i < n; i++)
        ans -= (unsigned long long)count(i);
    printf("Scenario %d:\n", kase);
    printf("There are %llu sites for making valid tracks\n", ans);
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif
    
    while (cin >> n && n > 0) {
        kase++; solve();
    }

    return 0;
}
