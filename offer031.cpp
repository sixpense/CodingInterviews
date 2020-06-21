// 031-连续子数组的最大和

#include <iostream>
#include <vector>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 暴力方法, 找出所有的子数组, 然后求其和, 取最大值
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) {
            return 0;
        }

        int sum, maxSum = INT_MIN;
        for(unsigned int i = 0; i < array.size(); i++) {
            sum = 0;
            for(unsigned int j = i; j < array.size(); j++) {
                sum += array[j];
                if(sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};

// 动态规划
// 用函数f(i)表示第i个数字结尾的子数组的最大和
class Solution_1 {
    int dp[1000];
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) {
            return 0;
        }

        int maxSum = INT_MIN;
        dp[0] = array[0];

        for(unsigned int i = 1; i < array.size(); i++) {
            if(dp[i - 1] <= 0) {
                dp[i] = array[i];
            }
            else {
                dp[i] = array[i] + dp[i - 1];
            }

            if(dp[i] > maxSum) {
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};

// 贪心算法
// 如果当前和为负数, 那么就放弃前面的累加和, 从数组中的下一个树开始计数
// 否则我们就继续累加, 并保存当前的累计和

class Solution_2 {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() ==  0) {
            return 0;
        }

        int maxNum = INT_MIN;

        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < array.size(); i++) {
            sum += array[i];
            debug <<sum <<endl;

            if(sum < 0) {
                sum = 0;
            }
            else if(sum > maxSum) {
                maxSum = sum;
            }

            // 保存数据的最大值, 为了排除整个数组全为负数的特殊情况
            if (array[i] > maxNum) {
                maxNum = array[i];
            }
        }
        return (maxNum > 0) ? maxSum : maxNum;
    }
};


int __tmain() {
    Solution solu;

    int arr1[] = {6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec1) <<endl;

    int arr2[] = { -2, -8, -1, -5, -9 };
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec2) <<endl;

    return 0;
}
