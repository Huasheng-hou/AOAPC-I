//
//  uva10079.cpp
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

// 

using namespace std;

typedef unsigned long long ull;

const int maxn = 210000010;
int n;
ull d[maxn];

void init() {
    
    d[0] = 1;
    for (int i = 1; i < maxn; i++)
        d[i] = d[i-1] + i;
}

void solve() {
    cout << d[n] << endl;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    while (cin >> n && n >= 0) {
        solve();
    }

    return 0;
}
