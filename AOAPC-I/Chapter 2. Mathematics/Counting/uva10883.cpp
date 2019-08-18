//
//  uva10883.cpp
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

// 超级平均数

using namespace std;

const int maxn = 50000;
int N, n, kase = 1;;
double num[maxn];

void solve() {

    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> num[i];
        
    long double coeff = 0;
    for (int i = 1; i <= n-1; i++) coeff -= logl(2); // 使用log来提高精度，防止溢出
    
    long double ans = 0;
    for (int i = 0; i <= n-1; i++) {
        
        ans += num[i] * exp(coeff);
        coeff += logl(n-1-i);
        coeff -= logl(i+1);
    }
    
    printf("Case #%d: %.3Lf\n", kase, ans);
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    cin >> N;
    for (kase = 1; kase <= N; kase++) solve();

    return 0;
}
