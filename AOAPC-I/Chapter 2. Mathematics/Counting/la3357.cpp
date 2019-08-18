//
//  la3357.cpp
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

// uva 1350 递推，类似 Fibonacci

using namespace std;

typedef unsigned long long ll;

const int maxn = 100;
const int maxk = 9e7;
ll T, K;
ll f[maxn], cnt[maxn];

void init() {
    
    f[0] = 0; f[1] = 1; f[2] = 1; f[3] = 2;
    cnt[0] = 0; cnt[1] = 1; cnt[2] = 2; cnt[3] = 4;
    for (int i = 4; i < maxn; i++) {
        f[i] = f[i-1] + f[i-2];
        cnt[i] = f[i] + cnt[i-1];
        if (cnt[i] > maxk) break;
    }
}

void solve() {

    if (K == 1) { cout << "1\n"; return; }
    if (K == 2) { cout << "10\n"; return; }
    if (K == 3) { cout << "100\n"; return; }
    if (K == 4) { cout << "101\n"; return; }
    int d = 1;
    while (d < maxn) {
        if (cnt[d] >= K) break;
        d++;
    }
    K -= cnt[d-1];
    
    string ans;
    ans.push_back('1'); ans.push_back('0');
    while (true) {
        if (K > f[d-1]) {
            ans.push_back('1'); K -= f[d-1]; d--;
            if (d <= 2) break; // 判断是否还需要再加 0
            ans.push_back('0'); d-=1;
        } else {
            ans.push_back('0');
            d--;
        }
        if (d <= 2) break;
    }
    cout << ans << "\n";
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    cin >> T;
    while (T--) {
        cin >> K;
        solve();
    }

    return 0;
}
