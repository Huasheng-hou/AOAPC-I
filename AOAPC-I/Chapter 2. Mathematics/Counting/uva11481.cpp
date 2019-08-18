//
//  uva11481.cpp
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

// 容斥原理 Accepted!

using namespace std;

typedef long long ll;

const int maxN = 1010;
ll mod = 1e9+7;
ll T, N, M, K, kase, res[maxN], inv[maxN];

// 扩展欧几里德算法，求 x*a + y*b = d 中 x 和 y 的值
void gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll Inv(ll a, ll n) {
    ll d, x, y;
    gcd(a, n, d, x, y);
    return d == 1 ? (x+n)%n : -1;
}

void init() {
    
    res[0] = 1; inv[0] = 1; // 注意乘法逆的初始化
    for (int i = 1; i < maxN; i++) res[i] = ((ll)i*res[i-1]) % mod;
    for (int i = 1; i < maxN; i++) inv[i] = Inv(res[i], mod);
}

ll cal(ll n, ll m) {
    
    if (m == 0) return 1;
    ll ans = (res[n] * inv[m]) % mod;
    ans = (ans * inv[n-m]) % mod;
    
    return ans;
}

void solve() {

    cin >> N >> M >> K;
    
    ll ans = res[N-K];
    for (int i = 1; i <= M-K; i++) {
        if (i % 2) {
            ans = (ans + mod - (cal(M-K, i) * res[N-K-i])%mod) % mod;
        } else {
            ans = (ans + cal(M-K, i) * res[N-K-i]) % mod;
        }
    }
    ans = (ans*cal(M, K))%mod;
    char out[100];
    sprintf(out, "Case %lld: %lld\n", kase, ans);
    cout << out;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif
    
    init();
    
    cin >> T;
    for (kase = 1; kase <= T; kase++) solve();

    return 0;
}
