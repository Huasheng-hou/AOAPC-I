//
//  uva11529.cpp
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

// Strange tax, 点在三角形内, Accepted! 0.710s

using namespace std;

const int maxn = 1210;
int n, kase = 0;
double x[maxn], y[maxn];
long double r[maxn];

long count(int k) {
    
    vector<long double> angle;
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        angle.push_back(atan2l(y[i]-y[k], x[i]-x[k]));
    }
    
    sort(angle.begin(), angle.end());
    
    int m = n-1;
    long long c = 0; int j = 1;
    for (int i = 0; i < m; i++) {
        while (j <= m-1) {
            long double p1 = angle[(i+j)%m];
            long double p2 = angle[i];
            long double cross = p1-p2;
            if (cross < 0) cross += 2*M_PI;
            if (cross > M_PI) {
                j--;
                break;
            }
            j++;
        }
        if (j > m-1) j--;
        c += (j)*(j-1)/2;
        j--;
    }
    
    return c;
}

void solve() {

    long double num = 0;
    for (int i = 0; i < n; i++) {
        num += count(i);
    }
    num = (unsigned long long)(n-3) * n * (n-1) / 2 * (n-2) / 3  - num;
    
    long double ans = num / n * 6 / (n-1) / (n-2);
    char out[100];
    sprintf(out, "City %d: %.2Lf\n", kase, ans);
    cout << out;
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (cin >> n && n > 0) {
        kase++;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        solve();
    }

    return 0;
}
