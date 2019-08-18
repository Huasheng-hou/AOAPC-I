//
//  uva10128.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/17.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// Accepted

using namespace std;

typedef unsigned long long ull;

const int maxn = 15;
int T, n, p, r;
ull d[maxn][maxn][maxn];

void init() {
    
    memset(d, 0, sizeof(d));
    d[1][1][1] = 1;
    
    for (int i = 2; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            for (int k = 1; k < maxn; k++)
                d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + (i-2)*d[i-1][j][k];
}

void solve() {

    cin >> n >> p >> r;
    cout << d[n][p][r] << "\n";
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    
    cin >> T;
    while (T--) solve();

    return 0;
}
