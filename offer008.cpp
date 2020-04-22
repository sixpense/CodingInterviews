// 008-旋转数组的最小数字

#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain
    #define debug cout
#else
    #define debug 0 && cout
#endif


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) {
            debug <<"非法输入" <<endl;
            return 0;
        }

        int mid = 0;
        int low = 0, high = rotateArray.size() - 1;
        if(rotateArray[low] < rotateArray[high]) {
            debug <<"数组未被旋转" <<endl;
        }

        while(rotateArray[low] >= rotateArray[high]) {
            // 如果前一个元素和后一个元素差一位
            // 说明找到了最大最小元素
            if((high - low) == 1) {
                mid = high;
                debug << "min = " <<low <<", high = " <<high <<endl;
                break;
            }
            mid = (high + low) / 2;
            debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high];

            if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high]) {
                debug <<"low == mid == high, so we should order it." <<endl;
                return MinOrder(rotateArray, low, high);
            }

            if(rotateArray[mid] >= rotateArray[low]) {
                low = mid;
            }
            else if(rotateArray[mid] <= rotateArray[high]) {
                high = mid;
            }
        }
        return rotateArray[mid];
    }
private:
    int MinOrder(vector<int> &num, int low, int high) {
        int result = num[low];
        for(int i = low + 1; i < high; i++) {
            if(num[i] < result) {
                result = num[i];
            }
        }
        return result;
    }
};

int __tmain() {
    int a[] = {3, 4, 5, 1, 2};
    vector<int> vec(a, a+5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}
