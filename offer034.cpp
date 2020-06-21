// 034-丑数(Ugly Number)
// 把只包含因子2, 3, 5的数称为丑数, 并求出从小到大的第N个丑数

#include <iostream>
using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
protected:
    int ugly[10000];
    int min(int a, int b, int c) {
        int temp = (a < b ? a : b);
        return (temp < c ? temp : c);
    }

public:
    int GetUglyNumber_Solution(int N) {
        ugly[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;

        int index = 1;
        while(index < N) {
            int val = min(ugly[index2] * 2, ugly[index3] * 3, ugly[index5] * 5);
            if(val == ugly[index2] * 2) {
                ++index2;
            }
            if(val == ugly[index3] * 3) {
                ++index3;
            }
            if(val == ugly[index5] * 5) {
                ++index5;
            }
            ugly[index++] = val;
        }
        int result = ugly[N - 1];
        return result;
    }
};

int __tmain() {
    Solution solu;
    cout <<solu.GetUglyNumber_Solution(55) <<endl;
    return 0;
}
