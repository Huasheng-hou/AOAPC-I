//
//  uva12299.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>

// * RMQ With Shifts, Interval Tree

using namespace std;

static const int maxN = 100000 + 2;
static int minv[2*maxN];
static int a[maxN];

typedef pair<int, int> Interval;

class DynamicRMQ {
    int n, q;
    
public:
    void solve() {
        
        memset(minv, 0, sizeof(minv));
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a+i);
        }
        
        Interval root = make_pair(1, n);
        int ans = query(1, root.first, root.second);
        printf("%d", ans);
        printf("\n");
    }
    
private:
    int query(int o, int l, int r) {
        
        if (minv[o]) return minv[o];
        if (l - r <= 1) { minv[o] = min(a[l], a[r]); return minv[o]; }
        
        int m = (r+l) / 2;
        int ret = min(query(2*o, l, m), query(2*o-1, m, r));
        minv[o] = ret;
        
        return ret;
    }
};
