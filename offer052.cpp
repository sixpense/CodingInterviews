// 052-构建乘积数组
// 给定一个数组A[0, 1, 2, ... , n-1], 构建一个数组B[0, 1, 2, ... , n-1]
// 其中B中的元素为数组A不包括第i位的所有乘积

#include <iostream>
#include <vector>

using namesace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 先看成是一个矩阵, 先计算下三角的乘积, 在计算上三角的乘积
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> res(n);

        for(int i = 0, temp = 1; i < n; i++) {
            res[i] = temp;
            temp *= A[i];
        }
        for(int i = n - 1, temp = 1; i >= 0; i--) {
            res[i] *= temp;
            temp *= A[i];
        }
        return res;
    }
}

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B(n);
        
        int temp;
        
        if(n != 0) {
            B[0] = 1;
            for(int i = 1; i < n; i++) {
                B[i] = B[i-1] * A[i-1];
            }
            int temp = 1;
            for(int j = n - 2; j >= 0; j--) {
                temp *= A[j+1];
                B[j] *= temp;
            }
        }
        return B;
    
    }
};
