/*
 * 065-滑动窗口的最大值
 * 给定一个数组和滑动窗口的大小, 找出所有滑动窗口里数值的最大值
 * 例如输入数组{2,3,4,2,6,2,5,2}及滑动窗口大小为3, 输出数组为{4,4,6,6,6,5}.
 */

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

#include <climits>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

// 暴力方法
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if(num.size() == 0 || size == 0) {
            return res;
        }
        for(int start = 0; start <= (int)(num.size() - size); start++) {
            int end = start + size;
            int max = INT_MIN;
            for(int index = start; index < end; index++) {
                if(num[index] > max) {
                    max = num[index];
                }
            }
            debug <<"[" <<start <<", " <<end <<"], max = " <<max <<endl;
            res.push_back(max);
        }
        return res;
    }
};

int __tmain() {
    Solution solu;

    int array[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));

    return 0;
}


class Solution_Max_Set {
    typedef pair<int, int> Pair;
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        vector<int> result;
        priority_queue<Pair> Q;
        if(num.size() < size || size < 1) {
            return result;
        }
        for(int i = 0; i < size - 1; i++) {
            Q.push(Pair(num[i], i));
        }
        for(int i = size - 1; i < num.size(); i++) {
            Q.push(Pair(num[i], i));
            Pair p = Q.top();
            while(p.second < i - (size - 1)) {
                Q.pop();
                p = Q.top();
            }
            result.push_back(p.first);
        }
        return result;
    }
};
