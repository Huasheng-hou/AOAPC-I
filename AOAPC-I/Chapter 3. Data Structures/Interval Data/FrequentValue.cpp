//
//  FrequentValue.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/8.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>

// * RMQ(Range Minimum Query)，Tarjan 的 Sparse-Table 算法

using namespace std;

static const int maxN = 100000+2;
static const int logN = 18;

static int a[maxN], sum[maxN], c[maxN], v[maxN];
static int d[maxN][logN];

class FrequentValue {
    int n, q, L, R;
    
public:
    void solve() {
        
        while (cin >> n >> q) {
            
            memset(c, 0, sizeof(c));
            
            int value = 0, cnt = 0;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                if (value != a[i]) {
                    value = a[i]; v[cnt] = a[i]; cnt++;
                }
                c[cnt]++;
            }
            sum[0] = 0;
            for (int i = 1; i <= cnt; i++) {
                sum[i] = sum[i-1] + c[i];
            }
            
            RMQ(cnt);
            for (int k = 1; k <= q; k++) {
                cin >> L >> R;
                int left = 1, right = cnt, ans = 0;
                for (int i = 1; i <= cnt; i++) {
                 
                    // * 属于一个段的特殊情况
                    if (sum[i] >= L && sum[i] >= R && sum[i-1] < L && sum[i-1] < R) {
                        ans = R-L+1; break;
                    }
                }
                for (int i = 1; i <= cnt; i++) {
                    if (sum[i] >= L) {
                        L = sum[i] - L + 1; left = i+1; break;
                    }
                }
                for (int i = 1; i <= cnt; i++) {
                    if (sum[i] >= R) {
                        R = R - sum[i-1]; right = i-1; break;
                    }
                }
                
                if (ans) {
                    cout << ans;
                    cout << "\n";
                    continue;
                }
                ans = max(L, R);
                if (right >= left) {
                    ans = max(ans, Query(left, right));
                }
                
                cout << ans << "\n";
            }
        }
    }
    
private:
    void RMQ(int cnt) {
        
        for (int i = 0; i <= cnt; i++) d[i][0] = c[i];
        for (int j = 1; (1<<j) <= n; j++)
            for (int i = 1; i + (1<<j) - 1 < n; i++)
                d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
    }
    
    int Query(int left, int right) {
        
        int k = 0;
        while (1<<(k+1) <= right-left+1) k++;
        return max(d[left][k], d[right-(1<<k)+1][k]);
    }
};
