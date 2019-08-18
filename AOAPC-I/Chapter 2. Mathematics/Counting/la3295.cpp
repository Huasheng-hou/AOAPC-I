//
//  la3295.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/15.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// Counting Triangles

using namespace std;

typedef unsigned long long ul;

const int maxn = 1010;
int n, m, kase = 0;
ul d[maxn][maxn], pre[maxn][maxn];

long gcd(long a, long b) { return a%b ? gcd(b, a%b) : b; }

ul C3(long n) {
    return n * (n-1) / 2 * (n-2) / 3;
}

void init() {
    
    memset(d, 0, sizeof(d)); memset(pre, 0, sizeof(pre));
    
    // 统计点到点阵的情况
    for (int i = 2; i < maxn; i++)
        for (int j = 2; j < maxn; j++) // 容斥原理
            d[i][j] = d[i][j-1] + d[i-1][j] - d[i-1][j-1] + gcd(i, j) - 1;

    // 统计点阵中各个点之间的情况
    for (int i = 2; i < maxn; i++)
        for (int j = 2; j < maxn; j++) // 容斥原理
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + d[i][j];
}

void solve() {

    n++; m++;
    ul ans = C3(n*m);
    
    if (n >= 3) ans -= m * C3(n);
    if (m >= 3) ans -= n * C3(m);

    ans -= pre[n-1][m-1];
    ans -= pre[n-1][m-1];
    
    char out[100];
    sprintf(out, "Case %d: %llu\n", kase, ans);
    cout << out;
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    init();
    while (cin >> n >> m && n > 0) {
        kase++; solve();
    }

    return 0;
}
