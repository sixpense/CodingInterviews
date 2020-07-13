// 041-和为S的两个数字
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

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> res;
        if(array.size() < 2) {
            return res;
        }
        int start = 0, end = array.size() - 1;
        long curSum;

        while(start < end) {
            curSum = array[start] + array[end];
            if(curSum == sum) {
                res.push_back(array[start]);
                res.push_back(array[end]);

                break;
            }
            else if(curSum < sum) {
                start++;
            }
            else {
                end--;
            }
        }
        return res;
    }
};

// 和为S的连续正数序列
// 采用滑动窗口

class Solution_1 {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> currRes;

        if(sum < 3) {
            return res;
        }
        int begin = 1, end = 2, mid = (sum + 1) / 2;
        int currSum = begin + end;
        while(begin < mid && end < sum) {
            if(currSum == sum) {
                currRes.clear();
                for(int i = begin; i <= end; i++) {
                    debug <<i <<" ";
                    currRes.push_back(i);
                }
                debug <<endl;
                res.push_back(currRes);

                end++;
                currSum += end;
            }
            else if(currSum > sum) {
                currSum -= begin;
                begin++;
            }
            else if(currSum < sum) {
                end++;
                currSum += end;
            }
        }
        return res;
    }
};

int __tmain() {
    Solution_1 solu;
    vector<vector<int>> res = solu.FindContinuousSequence(100);

    debug <<"Total Count = " <<res.size() <<endl;
    for(unsigned int i = 0; i < res.size(); i++) {
        debug <<"Count = " << i <<", Size = " <<res[i].size() <<endl;
        for(unsigned int j = 0; j < res[i].size(); j++) {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}
