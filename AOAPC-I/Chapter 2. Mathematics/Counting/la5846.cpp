//
//  la5846.cpp
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

// Neon Sign, 容斥原理求同色三角形, Accepted!

using namespace std;

const int maxN = 1010;
int T, N, x[maxN], y[maxN];

void solve() {

    cin >> N;
    
    memset(x, 0, sizeof(x)); memset(y, 0, sizeof(y));
    
    long long ans = N * (N-1) * (N-2) / 3 / 2;
    
    for (int i = 1; i <= N-1; i++) {
        int in;
        for (int j = i+1; j<= N; j++) {
            cin >> in;
            if (in) {
    
                x[i]++; x[j]++;
            } else {
                
                y[i]++; y[j]++;
            }
        }
    }
    
    long long sum = 0;
    for (int i = 1; i <= N; i++) sum += x[i]*y[i];
    ans -= sum/2;
    
    cout << ans << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    cin >> T;
    while (T--) solve();

    return 0;
}
