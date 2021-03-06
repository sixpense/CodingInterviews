// 014-调整数组顺序使奇数位于偶数前


#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug 0 && cout

#endif

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 1) {
            return ;
        }
        bool isSwap = false;
        for(int i = 0; i < array.size(); i++) {         //冒泡排序
            isSwap = false;
            for(int j = array.size() - 1; j > i; j--) {
                if(array[j] % 2 == 1 && array[j - 1] % 2 == 0) {
                    swap(array[j], array[j - 1]);
                    isSwap = true;
                }
            }
            if(isSwap == false) {
                break;
            }
        }
    }
};

int __tmain() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++) {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++) {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}
