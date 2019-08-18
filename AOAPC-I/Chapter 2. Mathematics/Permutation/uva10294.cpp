//
//  uva10294.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/18.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

// 等价类计数问题

using namespace std;

typedef unsigned long long ull;

int N, t;

int gcd(int a, int b) { return a%b ? gcd(b, a%b) : b; }

void solve() {

    ull a = 0;
    ull b = 0;
    for (int i = 1; i <= N; i++)
        a += (ull)powl((long double)t, gcd(N, i));
    
    if (N % 2) {
        b += (ull)powl(t, (N+1)/2) * (ull)N;
    } else {
        b += (ull)N * (ull)powl(t, N/2) / 2;
        b += (ull)N * (ull)powl(t, N/2 + 1) / 2;
    }
    
    ull nn = a/N;
    ull nb = (a+b)/N/2;
    
    cout << nn << " " << nb << endl;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    while (cin >> N >> t && N > 0 && t > 0)
        solve();

    return 0;
}
