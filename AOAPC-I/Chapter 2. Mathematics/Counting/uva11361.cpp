//
//  uva11361.cpp
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

// Div-Sum Property

using namespace std;

const int maxK = 1000;
const int Digit = 11;
int T, A, B, K, d[Digit][maxK][maxK];

int DP(int a, int m1, int m2) {
    if (a < K) return 0;
    int &ans = d[0][0][0];
    return ans;
}

void solve() {

    cin >> A, B, K;
    
//    int n1 = DP(A, <#int m1#>, <#int m2#>)
//    cout << DP(B)-DP(A-1) << "\n";
}

int main() {

    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    cin >> T; while(T--) solve();

    return 0;
}
