//
//  uva11038.cpp
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

// m 到 n 之间0出现的个数, Accepted!

using namespace std;

const int maxD = 11;
const unsigned int minus1 = ~0;
unsigned int m, n;
unsigned int q[maxD];

int idx(char c) { return c-'0'; }

void init() {
    
    q[0] = 0; q[1] = 1;
    for (int i = 2; i < maxD; i++) q[i] = 10*q[i-1]+pow(10, i-1); // i 位数出现 0 的个数
}

unsigned int f(unsigned int a) {
    
    char digit[11];
    unsigned int ans = 0; sprintf(digit, "%u", a);
    
    int d = (int)strlen(digit);
    
    if (d < 1) return 0;
    if (d == 1) return 1;
    
    int t = 1, m = idx(digit[0]);
    
    ans += f((unsigned int)pow(10, d-1)-1); // 递归求 (0, 10^(d-1)) 区间内的0个数
    ans += (unsigned int)(m-1) * (unsigned int)q[d-1];
    
    unsigned int next;
    
    while (t < d) {
        m = idx(digit[t]);
        if (m == 0) {
            sscanf(digit+t, "%u", &next);
            ans += next + 1;
        } else {
            ans += (unsigned int)pow(10, d-t-1); // 下一位是0，取 d-t-1 位的全排列
            ans += (unsigned int)(m) * (unsigned int)q[d-t-1];
        }
        t++;
    }
    
    return ans;
}

void solve() {

    unsigned int ans = f(n);
    ans = m == 0 ? ans : ans - f(m-1);
    cout << ans << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    init();
    while (cin >> m >> n && m != minus1) solve();

    return 0;
}
