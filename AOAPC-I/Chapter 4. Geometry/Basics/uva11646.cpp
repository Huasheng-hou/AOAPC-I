//
//  uva11646.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/9.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include "math.h"

using namespace std;

int a, b, kase = 0;
char c[10];

int main() {
    
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC-I/AOAPC-I/Inputs/output","w",stdout);

    while (scanf("%d%s%d", &a, c, &b) == 3) {
        kase++;
        
        long double ratio = (float)b / (float)a;
        long double coefficient = 2*sqrtl(a*a+b*b)*atanl(ratio) + 2*a;
        long double x = 400 / coefficient;
        
        long double lenth = x * (long double)a;
        long double width = x * (long double)b;
        
        printf("Case %d: %.10Lf %.10Lf\n", kase, lenth, width);
    }
    
    return 0;
}
