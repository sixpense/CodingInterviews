// 010-二进制中1的个数

// 把一个整数n减去1，再和原来的整数做与运算，会把该整数最右边一个1变成0，那么该整数有多少个1，就会进行多少次与运算.

#include <iostream>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
public:
    int Number0f1(int n) {
        int count = 0;
        while(n) {
            count++;
            n = n & (n - 1);
        }

        return count;
    }
};

#include <cmath>

int __tmain() {
    cout <<"sizeof(long): " <<sizeof(long) <<endl;
    Solution solu;
    cout <<solu.Number0f1(1) <<endl;
    cout <<solu.Number0f1(2) <<endl;
    cout <<solu.Number0f1(-2134893492) <<endl;

    return 0;
}

