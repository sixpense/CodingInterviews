// 038-数字在排序数组中出现的次数
// 统计一个数字在排序数组中出现的次数


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

#ifdef __tmain


// 暴力统计
class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if(data.size() == 0) {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0; i < data.size() && data[i] <= k; i++) {
            if(data[i] == k) {
                count++;
            }
        }
        return count;
    }
};

// 使用STL中特定的计算功能
class Solution_1 {
public:
    int GetNumberOfK(vector<int> data, int k) {
        multiset<int> mData;
        for(int i = 0; i < data.size(); i++) {
            mData.insert(data[i]);
        }
        return mData.count(k);
    }
}

int __tmain() {
    Solution solu;

    int arr[] = {1, 2, 3, 3, 3, 4, 5};
    vecotr<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 3) <<endl;

    return 0;
}
