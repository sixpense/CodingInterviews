// 032-计算从1到n整数中出现的次数

#include <iostream>

using namespace std;


// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 暴力方法
// 循环所有1~n中的每个number, 计算number出现的次数
class Solution {
public:
    /* [NumberOf1BetweenAndN_Solution] 统计1到n的整数中1出现的次数
     * @param                           [整数n]
     * @param                           [1到n的整数出现的次数]
     */
    int NumberOf1BetweenAndN_Solution(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            count += NumberOf1(i);
        }
        return count;
    }
protected:
    /* [NumberOf1]                      统计number中1出现的次数
     * @param                           [待处理的数字]
     * @param                           [numbers中1出现的次数]
     */
    int NumberOf1(int number) {
        int count = 0;
        while(number != 0) {
            if(number % 10 ==1) {
                count++;
            }
            number /= 10;
        }
        return count;
    }
};

class Solution_1 {
public:
    int NumberOf1BetweenAndN_Solution(int n) {
        return CountOne(n);
    }

    int CountOne(int n) {
        long count = 0;

        if(n == 0) {
            count = 0;
        }
        else if(n > 1 && n < 10) {
            count = 1;
        }
        else {
            long highest = n;
            int bit = 0;
            while(highest >= 10) {
                highest = highest / 10;
                bit++;
            }

            int weight = pow(10, bit);

            if(highest == 1) {
                count = CountOne(weight - 1) + CountOne(n - weight) + (n - weight + 1);
            }
            else {
                count = highest * CountOne(weight - 1) + CountOne(n - weight * highest) + weight;
            }
        }
        return count;
    }
};

int __tmain() {
    Solution solu;
    cout <<solu.NumberOf1BetweenAndN_Solution(12) <<endl;
    cout <<solu.NumberOf1BetweenAndN_Solution(100) <<endl;
    cout <<solu.NumberOf1BetweenAndN_Solution(1000) <<endl;
}
