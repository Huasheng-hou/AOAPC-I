//
//  uva580.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/18.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// Accepted

using namespace std;

const int maxl = 32;
int n, d[maxl][3];

void init() {
    
    d[1][0] = 1; d[1][1] = 1; d[1][2] = 0;
    for (int i = 2; i < maxl; i++) {
        
        d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1] = d[i-1][0];
        d[i][2] = d[i-1][1];
    }
}

void solve() {

    int ans = (1<<n) - d[n][0] - d[n][1] - d[n][2];
    cout << ans << endl;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    while (cin >> n && n > 0) solve();

    return 0;
}
