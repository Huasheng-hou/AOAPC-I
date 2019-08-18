//
//  Substring.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/7.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <queue>
#include "string.h"

using namespace std;

static const int maxK = 20;
static const int maxP = 20;
static const int maxL = 100;
static const int Sigma = 26+26+10;

static int ch[maxK*maxP][Sigma];
static int f[maxK*maxP], match[maxK*maxP], vis[maxK*maxP][maxL];
static double dp[maxK*maxP][maxL];

class Substring {
    
    int T, K, N, L, kase, sz;
    char P[maxK][maxP+2];
    double prob[Sigma];
    
public:
    void solve() {
        
        cin >> T;
        for (kase = 1; kase <= T; kase++) {
            
            sz = 0; memset(ch, 0, sizeof(ch));
            memset(match, 0, sizeof(match));
            memset(vis, 0, sizeof(vis));
            memset(f, 0, sizeof(f));
            memset(prob, 0, sizeof(prob));
            
            cin >> K;
            for (int i = 0; i < K; i++) {
                cin >> P[i];
                insert(P[i]);
            }
            
            cin >> N;
            
            char c;
            for (int i = 0; i < N; i++) {
                cin >> c; cin >> prob[idx(c)];
            }
            cin >> L;
            
            getFail();
            double ans = DP(0, L);
            
            printf("Case #%d: %.6lf\n", kase, ans);
        }
    }
    
private:
    // * 构造 Trie
    void insert(char *p) {
        long len = strlen(p); int u = 0, v;
        for (int i = 0; i < len; i++) {
            v = idx(p[i]);
            if (!ch[u][v]) {
                sz++;
                ch[u][v] = sz;
            }
            u = ch[u][v];
        }
        match[u] = 1;
    }
    
    void getFail() {
        
        queue<int> Q;
        for (int i = 0; i < Sigma; i++) {
            int u = ch[0][i];
            if (u) { f[u] = 0; Q.push(u); }
        }
        
        // * BFS计算失配边
        while (!Q.empty()) {
            int r = Q.front(); Q.pop();
            for (int c = 0; c < Sigma; c++) {
                int u = ch[r][c];
                if (!u) { ch[r][c] = ch[f[r]][c]; continue; }
                Q.push(u);
                
                int v = f[r];
                while (v && !ch[v][c]) {
                    v = f[v];
                }
                f[u] = ch[v][c];
                match[u] |= match[f[u]]; // 失配边的match也要设置
            }
        }
    }
    
    double DP(int u, int L) {
        if (!L) return 1.0;
        if (vis[u][L]) return dp[u][L];
        vis[u][L] = 1;
        
        double &ans = dp[u][L];
        ans = 0.0;
        for (int i = 0; i < Sigma; i++) {
            if (!match[ch[u][i]]) {
                ans += prob[i] * DP(ch[u][i], L-1);
            }
        }
        
        return ans;
    }
    
    int idx(char c) {
        
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        if (c >= 'A' && c <= 'Z') return c - 'A' + 36;
        return 0;
    }
};
