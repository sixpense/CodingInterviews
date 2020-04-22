// 009-斐波那契数列
// [f(n+1), f(n)
//  f(n), f(n-1)] 矩阵是
// [1, 1,
//  1. 0]的(n-1)次方结果. 第一行第一列就是f(n).
//
//  a(n) = { a(n/2) * a(n/2);    n为偶数时
//         a((n-1)/2) * a((n-1)/2)}    n为奇数时
//
//  a(n) = a(n-1) + a(n-2)
//       = 2*a(n-2) + a(n-3)
//       = 3*a(n-3) + 2*a(n-4)
//       = 5*a(n-4) + 3*a(n-5)
//       = a(k)*a(n-k+1) + a(k-1)*a(n-k)
//
//  n = 2k
//  a(2k) = a(k)*a(k+1) + a(k-1)*a(k)
//        = a(k)*[a(k+1) + a(k-1)]
//        = a(k)*[a(k) + a(k-1)] + a(k)*a(k-1)
//        = (a(k))^2 + 2*a(k)a(k-1)
//
//  n = 2k - 1
//  a(2k - 1) = a(k)*a(k) + a(k-1)a(k-1)
//            = (a(k))^2 + (a(k-1))^2
//


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
public:
    static int pre;
    static int post;
    int temp;

    int Fibonacci(int n) {
        /*
         * 每次调用Fibonacci结束后:
         *     pre: Fibonacci(n)的值
         *     post: Fibonacci(n-1)的值
         */

        if(n <= 2) {
            if (n == 0) 
                return 0;
            pre = 1;
            post = 1;
            return pre;
        }

        if(n%2 == 1) {
            Fibonacci(n-1);
            pre = pre + post;
            post = pre - post;
            return pre;
        }

        Fibonacci(n/2);
        temp = pre;
        pre = pre * pre + 2 * pre * post;
        post = temp*temp + post*post;
        return pre;
    }
};

int Solution::pre = 0;
int Solution::post = 0;

int __tmain() {
    Solution solu;
    cout <<solu.Fibonacci(3) <<endl;
    return 0;
}
