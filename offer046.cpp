// 046不使用判断条件求1 + 2 + 3 + 4 +...
// 短路运算 0 && cout, 使条件为假值, 从而不执行输出语句

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
public:
    // 使用短路运算, 从n开始递减进程递归的相加运算
    // 当递归至0时使递归短路即可
    int SumRecursion(int n) {
        int ans = n;
        n && (ans += SumRecursion(n - 1));
        return ans;
    }
};

// 使用位运算来计算n * (n + 1) / 2
int Multi(int a, int b) {
    int res = 0;
    while(a != 0) {
        if((a & 1) != 0) {
            res += b;
        }
        a >>= 1;
        b <<= 1;
    }
    return 0;
}

// 循环用递归来代替
// 分支用短路运算来代替
int MultiRecursion(int a, int b) {
    static int res = 0;
    a && MultiRecursion(a >> 1, b << 1);
    (a & 1) && (res += b);

    return res;
}


// 最后完成代码如下
class Solution_1 {
public:
    int res;
    int Sum_Solution(int n) {
        res = 0;
        return (MultiRecursion(n, n + 1) >> 1);
    }

    int MultiRecursion(int a, int b) {
        a && MultiRecursion(a >> 1, b << 1);
        (a & 1) && (res += b);

        return res;
    }
};

int __tmain() {
    Solution_1 solu;

    cout << solu.Sum_Solution(90) <<endl;

    return 1;
}
