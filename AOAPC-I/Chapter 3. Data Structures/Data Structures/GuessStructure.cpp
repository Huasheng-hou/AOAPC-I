//
//  GuessStructure.cpp
//  AOAPC-I
//
//  Created by apple on 2019/8/7.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class GuessStructure {
    int n;
    stack<int> Stack;
    queue<int> Q;
    priority_queue<int> Heap;
    
public:
    void solve() {
        
        while (cin >> n) {
            
            while (!Stack.empty()) Stack.pop();
            while (!Q.empty()) Q.pop();
            while (!Heap.empty()) Heap.pop();
            
            int command, x, s = (1<<3) - 1;
            for (int i = 1; i <= n; i ++) {
                cin >> command >> x;
                if (command == 1) {
                    Stack.push(x);
                    Q.push(x);
                    Heap.push(x);
                } else {
                    
                    if (1 & s) {
                        if (!Stack.empty() && Stack.top() == x) {
                            Stack.pop();
                        } else {
                            s &= ~1;
                        }
                    }
                    if (1<<1 & s) {
                        if (!Q.empty() && Q.front() == x) {
                            Q.pop();
                        } else {
                            s &= ~(1<<1);
                        }
                    }
                    if (1<<2 & s) {
                        if (!Heap.empty() && Heap.top() == x) {
                            Heap.pop();
                        } else {
                            s &= ~(1<<2);
                        }
                    }
                }
            }
            if (s == 0) { cout << "impossible"; }
            else if (s == 1) { cout << "stack"; }
            else if (s == 1<<1) { cout << "queue"; }
            else if (s == 1<<2) { cout << "priority queue"; }
            else { cout << "not sure"; }
            cout << "\n";
        }
    }
};
