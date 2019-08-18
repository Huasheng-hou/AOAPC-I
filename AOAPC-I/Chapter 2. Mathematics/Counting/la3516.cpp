//
//  la3516.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/14.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// Exploring Pyramids, DP

using namespace std;

const int maxN = 310;
const long long mod = 1e9;
char s[maxN];
long long d[maxN][maxN];

long long DP(int i, int j) {
    
    if (i == j) return 1;
    if (s[i] != s[j]) return 0;
    long long &ans = d[i][j];
    if (ans >= 0) return ans;
    ans = 0;
    // i+1到k-1为第1个分支，其余为剩余的树
    for (int k = i+2; k <= j; k++) ans = (ans + DP(i+1, k-1)*DP(k, j)) % mod;
    return ans;
}

void solve() {

    memset(d, -1, sizeof(d));
    long long ans = DP(0, (int)strlen(s)-1);
    cout << ans;
    cout << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (cin >> s) solve();

    return 0;
}
