//
//  uva11538.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/11.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <math.h>

// Chess Queen, Accepted!

using namespace std;

long long N, M;

void solve() {

    long long c1, c2, c3;
    if (N > M) { long long tmp = M; M = N; N = tmp; }

    c1 = (N-1) * N * M;
    c2 = N * (M-1) * M;
    c3 = N*(N-1) * (3*M-N-1) / 3;
    c3 *= 2;
    
    long long ans = c1+c2+c3;
    cout << ans << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (cin >> N >> M && N >0 && M > 0) {
        solve();
    }

    return 0;
}
