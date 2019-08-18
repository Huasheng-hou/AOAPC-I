//
//  uva417.cpp
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

// Word Index Accepted

using namespace std;
const int maxn = 28;
const int maxd = 8;
const int num   = 26;
int d[maxn][maxd], sum[maxd];
char w[maxd];

int idx(char c) { return c - 'a' + 1; }

void init() {
    
    memset(d, 0, sizeof(d));
    
    for (int i = 1; i < maxn; i++) {
        d[i][0] = 1;
        d[i][1] = i;
        for (int j = 2; j < maxd; j++) {
            d[i][j] = (i-j+1)*d[i][j-1] / j;
        }
    }
    
    sum[0] = 0;
    for (int j = 1; j < maxd; j++) {
        sum[j] = sum[j-1] + d[26][j];
    }
}

void solve() {
    
    int ans = 0, len = (int)strlen(w);
    
    for (int i = 0; i < len; i++)
        for (int j = i+1; j < len; j++)
            if (w[i] >= w[j]) { cout << 0 << endl; return; }
    
    ans += sum[len-1];
    for (int j = 1; j < idx(w[0]); j++)
        ans += d[num-j][len-1];
    
    for (int i = len-1; i >= 1; i--) {
        for (int j = idx(w[i-1])+1; j < idx(w[i]); j++ )
            ans += d[num-j][len-i-1];
    }
    
    ans++;
    cout << ans << endl;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    while (cin >> w) solve();

    return 0;
}
