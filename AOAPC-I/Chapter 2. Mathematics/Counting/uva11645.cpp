//
//  uva11645.cpp
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

// 递推计数，求数字组合的通用方法

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll DIG = 1e13;
ll x, kase = 0, a, b;

void add(ll t) {
    
    b += t;
    a += b/DIG;
    b = b%DIG;
}

void solve() {

    a = 0; b = 0;
    ll tmp = x, d = 1;
    while (x > 1) { // 通过移位来向左枚举
        add((x >> 2) * d); // 末两位出现 '11' 的情况
        if ((x & 3) == 3) add((tmp&(d-1)) + 1); // 出现11时统计右边的值
        d <<= 1;
        x >>= 1;
    }
    if (a) {
        
        printf("%lld", a);
        printf("%013lld\n", b);
    } else {
        printf("%lld\n", b);
    }
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    while (cin >> x && x >= 0) {
        kase++;
        printf("Case %lld: ", kase);
        solve();
    }

    return 0;
}
