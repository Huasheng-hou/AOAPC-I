//
//  uva10673.cpp
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

// Accepted!

using namespace std;

typedef long long ll;

ll x, k;
int T;

void solve() {

    cin >> x >> k;
    if (x%k) cout << -x << " " << x; else cout << 0 << " " << k;
    cout << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    cin >> T;
    while (T--) solve();

    return 0;
}
