//
//  la3720.cpp
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

// Highway 容斥原理，点阵计数问题

using namespace std;

int gcd(int a, int b) { return a%b ? gcd(b, a%b) : b; }

const int maxn = 1010;
int n, m;
long long d[maxn][maxn], pre[maxn][maxn];

void solve() {

    cout << pre[n-1][m-1]*2 << "\n"; // 一共n-1行，m-1列格子
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif
    
    memset(d, 0, sizeof(d)); memset(pre, 0, sizeof(pre));
    
    // 从点(i,j)出发的直线条数
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            int t = gcd(i, j) == 1 ? 1 : 0;
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + t;
        }
    }
    
    // 矩形(i,j)出发的直线条数，容斥原理
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            pre[i][j] = pre[i-1][j] + pre[i][j-1] -pre[i-1][j-1] + d[i][j] - d[i/2][j/2];
    
    while (cin >> n >> m && n > 0) solve();

    return 0;
}
