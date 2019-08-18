//
//  uva11401.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int n;
long long f[1000010];

void solve() {

    f[3] = 0;
    for (long long x = 4; x <= 1000000; x++) {
        f[x] = f[x-1] + ((x-1)*(x-2)/2-(x-1)/2)/2;
    }
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    solve();
    while (cin >> n && n >= 3) {
        cout << f[n] << "\n";
    }

    return 0;
}
