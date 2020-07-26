// 047不用加减乘除做加法
// 写一个函数, 求两个整数之和, 要求在函数体内不得使用+ - * / 四则运算符号

#include <iostream>

using namespace std;

// 思路1:
// 通过C/C++内敛汇编AT&T, 直接使用add指令来进行相加操作
// AT&T语法第一个为源操作数, 第二个为目的操作数, 方向从左到右, 合乎自然.

class Solution {
public:
    int Add(int left, int right) {
        __asm__ __volatile__(
                // "lock;\n"
                "addl %1,%0;\n"         // 相当于 add b, a; 结果存在a中
                : "=m"(left)
                : "r"(right), "m"(left)
                );
        return left;
    }
};


// 位运算模拟加法

// 5 -=> 101 7 -=> 111

// 相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111=010

// 计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。

// 重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。

// 继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。

class Solution_1 {
public:
    int Add(int left, int right) {
        int temp;
        while(right != 0) {
            temp = left ^ right;
            right = (left & right) << 1;
            left = temp;
        }
    return left;
    }
};


int main() {
    Solution solu;

    cout << solu.Add(5, 7) <<endl;

    Solution_1 solu1;

    cout <<solu1.Add(5, 7) <<endl;

    return 0;
}
