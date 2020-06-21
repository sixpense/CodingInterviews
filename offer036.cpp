// 036-数组中逆序对
// 在数组中的两个数字, 如果前面一个数字大于后面的数字, 则这两个数字组成一个逆序对.
// 输入一个数组, 求出这个逆序对的总数.

#include <iostream>
#include <vector>

using namespace std;


#include <iostream>
using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 暴力解法
class Solution {
public:
    int InversePairs(vector<int> elem) {
        if(elem.size() == 0) {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0; i < elem.size(); i++) {
            for(unsigned int j = i + 1; j < elem.size(); j++) {
                if(elem[i] > elem[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int __tmain() {
    Solution solu;
    int arr[] = {7, 5, 6, 4};
    vector<int> vec(arr, arr+4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
