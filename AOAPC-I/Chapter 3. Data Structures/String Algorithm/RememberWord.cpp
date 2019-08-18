//
//  RememberWord.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/6.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <string.h>

// * 1401 Remember the Word, Trie（前缀树）

using namespace std;

static const int maxS   = 300000 + 2;
static const int Sigma  = 26;
static const int maxN   = 4000 * 100 + 10;

static int ch[maxN][Sigma], d[maxS], val[maxN];

class RememberWord {
    
    int S, L, kase = 0;
    char text[maxS], w[100+2];
    
public:
    void solve() {
        
        while (cin >> text >> S) {
            
            kase++;
            memset(ch, -1, sizeof(ch));
            memset(d, 0, sizeof(d));
            memset(val, 0, sizeof(val));
            
            L = (int)strlen(text);
            int pos = 0;
            
            for (int i = 0; i < S; i ++) {
                
                cin >> w; int len = (int)strlen(w);
                int u = 0, v;
                
                for (int j = 0; j < len; j++) {
                    
                    v = idx(w[j]);
                    if (ch[u][v] < 0) {
                        pos++;
                        ch[u][v] = pos;
                    }
                    u = ch[u][v];
                }
                val[u] ++;
            }
            DP();
            
            cout << "Case " << kase << ": ";
            cout << d[1];
            cout << "\n";
        }
    }
    
private:
    void DP() {
        
        d[L+1] = 1;
        for (int i = L; i >= 1; i --) {
            
            int u = 0, v;
            for (int j = i; j <= L; j++) {
                v = idx(text[j-1]);
                if (ch[u][v] >= 0) {
                    
                    u = ch[u][v];
                    if (val[u] > 0) d[i] += d[j+1];
                } else {
                    break;
                }
            }
        }
    }
    
    int idx(char c) { return c - 'a'; }
};
