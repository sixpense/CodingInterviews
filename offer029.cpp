// 029-数组中出现次数超过一半的数字
// 统计输入数组中次数超过一半的个数


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) {
            return 0;
        }
        else if(numbers.size() == 1) {
            return numbers[0];
        }

        sort(numbers.begin(), numbers.end());

        int res = 0;
        int count = 1;
        for(int i = 0; i < numbers.size() - 1; i++) {
            if(numbers[i] == numbers[i + 1]) {
                count++;
            }
            else {
                debug <<numbers[i] <<", count = " << count <<endl;
                count = 1;
            }
#ifdef __tmain
            if(i == numbers.size() - 2) {
                debug <<numbers[i + 1] <<", count = " <<count <<endl;
            }
#endif
            if(count > numbers.size() / 2) {
                res = numbers[i];
                break;
            }
        }
        return res;
    }
};

int __tmain() {
    int arr1[] = {5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout << solu.MoreThanHalfNum_Solution(vec1) <<endl;
}
