//
//  uva10237.cpp
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

// Bishops，分黑白色处理，递推计数

using namespace std;

typedef unsigned long long ll;

const int maxn = 32;
int n, k;
ll b[maxn][maxn*maxn], w[maxn][maxn*maxn];

void solve() {

    memset(b, 0, sizeof(b));
    memset(w, 0, sizeof(w));
    
    b[0][0] = 1; w[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        
        b[i][0] = b[i-1][0];
        int l = (i+1) / 2 * 2 - 1; // 对斜对角线进行了重新排列
        for (int j = 1; j <= l && j <= k; j++)
            b[i][j] = b[i-1][j] + (ll)(l-j+1)*b[i-1][j-1];
    }
    for (int i = 2; i <= n; i++) {
        
        w[i][0] = w[i-1][0];
        
        int l = i / 2 * 2; // 对斜对角线进行了重新排列
        for (int j = 1; j <= l && j <= k; j++)
            w[i][j] = w[i-1][j] + (ll)(l-j+1)*w[i-1][j-1];
    }
    
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans += b[n][i]*w[n][k-i];
    
    cout << ans << "\n";
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    while (cin >> n >> k && (n > 0 || k > 0)) {
//        if (k == 0) cout << 1 << "\n";
        solve();
    }

    return 0;
}
