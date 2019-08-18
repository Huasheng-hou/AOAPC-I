//
//  uva11806.cpp
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

// Cheerleaders, 容斥原理, Accepted!

using namespace std;

const int maxK = 510;
int T, M, N, K, kase, m = 1000007;
long long c[maxK][maxK];

void Combine() {
    
    memset(c, 0, sizeof(c)); // 对于C(r,s)，s>r的方案不存在，计数为0
    
    for (int i = 0; i < maxK; i++) {
        c[i][0] = 1; c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1]; // 求模不能用除法，只能用乘法和加法
            c[i][j] %= m;
        }
    }
}

void solve() {

    Combine();
    
    cin >> T;
    for (kase = 1; kase <= T; kase++) {
        cin >> M >> N >> K;
        
        int ans = 0;
        for (int s = 0; s < 1<<4; s++) {
            
            int b = 0, p = M, q = N;
            if (s & 1) { b++; p--; }
            if (s & 1<<1) { b++; p--; }
            if (s & 1<<2) { b++; q--; }
            if (s & 1<<3) { b++; q--; }
            
            if (b&1) {
                ans = (ans + m - c[p*q][K]) % m;
            } else {
                ans = (ans + c[p*q][K]) % m;
            }
        }
        cout << "Case " << kase << ": " << ans << "\n";
    }
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    solve();

    return 0;
}
