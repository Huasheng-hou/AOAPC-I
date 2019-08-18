//
//  PingPong.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/8.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <vector>

// * Binary Index Tree
// * 已经AC，uDebug数据有毒

using namespace std;

static const int maxN = 20000+2;

static inline int lowbit(int x) { return x&(-x); }

class PingPong {
    int T, N, a[maxN], c[maxN], d[maxN], e[maxN], f[maxN], maxa;
    vector<int> Fenwick;
    
public:
    void solve() {
        
        cin >> T;
        while (T--) {
            
            cin >> N; maxa = 0;
            for (int i = 1; i <= N; i++) {
                cin >> a[i]; maxa = max(maxa, a[i]);
            }
            maxa++;
            Fenwick.resize(maxa);
            fill(Fenwick.begin(), Fenwick.end(), 0);
            
            for (int i = 1; i <= N; i++) {
                c[i] = sum(a[i]);
                e[i] = sum(a[i] - 1);
                add(a[i], 1);
            }
            
            fill(Fenwick.begin(), Fenwick.end(), 0);
            for (int i = N; i >= 1; i--) {
                d[i] = sum(a[i]);
                f[i] = sum(a[i] - 1);
                add(a[i], 1);
            }
            
            long long ans = 0;
            for (int i = 1; i <= N; i++) {
                ans += (long long)c[i] * (N-i-f[i]) + (i-e[i]-1) * d[i];
            }
            cout << ans;
            cout << "\n";
        }
    }
    
private:
    void add(int x, int d) {
        while (x <= maxa) {
            Fenwick[x] += d; x += lowbit(x);
        }
    }
    
    int sum(int x) {
        int ret = 0;
        while (x > 0) {
            ret += Fenwick[x]; x -= lowbit(x);
        }
        return ret;
    }
};
