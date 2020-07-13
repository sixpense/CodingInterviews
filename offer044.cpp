// 044-扑克牌顺子
// 随机抽5张牌, 看是否是顺子, 其中大\小王可以看成是任何数字

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 排序后看0能否填补空缺
class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if(numbers.size() == 0) {
            return false;
        }

        sort(numbers.begin(), numbers.end());
        int left = 0;
        while(numbers[left] == 0) {
            left++;
        }
        debug <<"left = " <<left <<endl;

        for(int i = left + 1; i < numbers.size(); i++) {
            debug <<numbers[i - 1] <<", " <<numbers[i] <<endl;

            if(numbers[i] == numbers[i - 1]) {
                return false;
            }
            else {
                left -= (numbers[i] - numbers[i - 1] - 1);

            }
        }
        debug <<"left = " <<left <<endl;
        if(left >= 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

#define BIT_GET(numbers, pos) ((numbers) >> (pos) & 1)     // 用宏得到某数的某位
#define BIT_SET(numbers, pos) ((numbers) |= 1 << (pos))     // 把某位置1
#define BIT_CLR(numbers, pos) ((numbers) &= ~(1 << (pos)))  // 把某位清0
#define BIT_CPL(numbers, pos) ((numbers) ^= 1 << (pos))     // 把number的pos位取反

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if(numbers.size() != 5) {
            return false;
        }
        int min = INT_MAX;
        int max = INT_MIN;
        int flag = 0;

        for(int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];
            if(num < 0 || num > 13) {
                return false;
            }
            else if(num == 0) {
                continue;
            }

            if(BIT_GET(flag, num) == 1) {
                debug <<i <<", " <<num <<endl;
                return false;
            }
            else {
                BIT_SET(flag, num);
            }

            if(num > max) {
                max = num;
            }
            if(num < min) {
                min = num;
            }
            debug <<"max = " <<max <<", min = " <<min <<endl;

            if(max - min > 4) {
                debug <<"max = " <<max <<", min = " <<min <<endl;
                return false;
            }
        }
        return true;
    }
};

int __tmain() {
    Solution solu;

    int arr1[] = {1, 3, 2, 6, 4};
    vector<int> vec1(arr1, arr1 + 5);
    cout <<solu.IsContinuous(vec1) <<endl;

    int arr2[] = {3, 5, 1, 0, 4};
    vector<int> vec2(arr2, arr + 5);
    cout <<solu.IsContinuous(vec2) <<endl;

    int arr3[] = {1, 0, 0, 1, 0};
    vector<int> vec3(arr3, arr3 + 5);
    cout <<solu.IsContinuous(vec3) <<endl;
    return 0;
}
