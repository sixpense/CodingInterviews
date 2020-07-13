// 040-数组中只出现一次的数字
// 一个整型数组除了两个数字之外, 其他的数字都出现了两次, 请找出这两个只出现一次的数字


#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 分析
// 考察的是异或运算的特点: 两个相同的数异或结果为0.
// 划分两部分, 一部分是此位上有1, 另一部分是此位上没有1, 分别对每部分求异或.

class Solution {
public:

#define INT_SIZE (sizeof(int) * 9)

#define IS_BIT(number, index) (((number) & (1 << (index))) >>index)

    void FindNumsAppearOnce(vector<int> array, int *num1, int *num2) {
        *num1 = *num2 = 0;
        if(array.size() < 2) {
            return ;
        }

        int XOR = array[0];
        for(int i = 1; i < array.size(); i++) {
            XOR ^= array[i];
        }

        debug <<bitset<INT_SIZE>(XOR) <<endl;

        int index = 0, temp = 1;
        for(; index < INT_SIZE; index++) {
            if((XOR & temp) == temp) {
                break;
            }
            temp <<= 1;
        }
        debug <<index <<endl;
        if(index == INT_SIZE) {
            debug <<"no two numbers which once" <<endl;
            return ;
        }
        debug <<"find 1 in index = " <<index <<endl;
        debug <<IS_BIT(XOR, index) <<endl;
        // 那两个只出现一次的数字, 第index位必须不相同
        // 将数组划分成两部分, 一部分index位是0, 另一部分index位是1
        for(int i = 0; i < array.size(); i++) {
            if(IS_BIT(array[i], index) == 1) {
                *num1 ^= array[i];
            }
            else {
                *num2 ^= array[i];
            }
        }
    }
};

int __tmain() {
    Solution solu;

    int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
    vector<int> vec(arr, arr+8);

    int num1, num2;
    solu.FindNumsAppearOnce(vec, &num1, &num2);
    cout<<"RESULT: " <<num1 <<", " << num2 << endl;
    return 0;
}
