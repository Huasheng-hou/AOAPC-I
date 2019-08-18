//
//  uva10497.cpp
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

// 

using namespace std;

struct BigInteger {
    static const int BASE = 1e8;
    static const int WIDTH = 8;
    vector<int> s;
    
    BigInteger(int num=0) { *this = num; }
    BigInteger operator = (int num) { s.clear(); s.push_back(num); return *this; }
    
    BigInteger operator + (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    
    BigInteger operator += (const BigInteger& b) { *this = *this + b; return *this; }
    BigInteger operator -= (const BigInteger& b) { *this = *this - b; return *this; }
    
    void adjust() {
        while(s.size() > 1 && s.back() == 0) s.pop_back();
    }
    
    BigInteger operator - (const BigInteger& b) const {
        BigInteger c;
        c.s.resize(s.size());
        for(int i = 0, g = 0; i < s.size(); i++) {
            c.s[i] = s[i] - g;
            g = 0;
            int sub = (i < b.s.size() ? b.s[i] : 0);
            if(c.s[i] < sub) { g = 1; c.s[i] += BASE; }
            c.s[i] -= sub;
        }
        c.adjust();
        return c;
    }
    
    BigInteger operator * (const BigInteger& b) const {
        BigInteger c;
        c.s.resize(s.size() + b.s.size() + 1);
        fill(c.s.begin(), c.s.end(), 0);
        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < b.s.size(); j++) {
                long long sum = (long long)s[i] * b.s[j] + c.s[i+j];
                c.s[i+j+1] += sum / BASE;
                c.s[i+j] = sum % BASE;
            }
        c.adjust();
        return c;
    }
};

ostream& operator << (ostream &out, const BigInteger& x) {
    out << x.s.back();
    for(int i = (int)x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

const int maxn = 805;
int n;
BigInteger f[maxn];

void init() {
    
    f[0] = 1; f[1] = 0;
    for (int i = 1; i < maxn; i++) f[i] = (f[i-1]+f[i-2])*(i-1);
}

void solve() {

    cout << f[n] << endl;
}

int main() {

#ifdef UVA
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);
#endif

    init();
    while (cin >> n && n > 0)
        solve();

    return 0;
}
