// 049-将字符串转化为整数
// 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。

#include <iostream>

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
    int StrToInt(string str) {
        string::iterator pstr = str.begin();
        while(*pstr == ' ') {
            pstr++;
        }

        bool minus=false;                   // 符号位

        // 判断符号位+ -
        if(*pstr == '+') {
            pstr++;
        }
        else if(*pstr == '-') {
            pstr++;
            minus = true;
        }

        // 关键函数
        long long int value = 0;
        for (; *pstr != '\0'; pstr++) {
            if('0' <= *pstr && *pstr <= '9') {
                value *= 10;
                value += *pstr - '0';
#ifdef DEBUG
                printf("value = %lld\n", value);
#endif
            }
            else {
                break;
            }

            // 解决OVER_Flow的问题
            // INT_MAX 2147483647
            // INT_MIX -2147483648     minus = true
            if((minus == true && value > (unsigned long)(INT_MAX) + 1) || (minus == false && value > INT_MAX)) {
                debug <<value <<", " <<INT_MAX <<endl;
                debug <<"to max than int" <<endl;
                break;
            }
        }
        while(true) {
            if(minus == true) {
                value = -value;
            }
            if(value >= INT_MAX) {
                value = INT_MAX;
            }

            if(value <= INT_MIN) {
                value = INT_MIN;
            }

            return (int)value;
        }

    }
};

int main() {
    Solution solu;
    
    cout <<"INT_MAX: " <<INT_MAX <<endl;
    cout <<"INT_MIN: " <<INT_MIN <<endl;
    cout <<solu.StrToInt("1a33") <<endl;
    cout <<solu.StrToInt("193938393839389383939") <<endl;
    cout <<solu.StrToInt("123") <<endl;
    cout <<solu.StrToInt("-23r2") <<endl;
}
