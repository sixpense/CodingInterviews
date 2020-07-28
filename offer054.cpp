// 054-表示数值的字符串
// 请实现一个函数用来判断字符串是否表示数值(包含整数和小数)
// 例如"+100", "5e2", "-123", "3.14258392", "-1E-16"都表示数值
// 但"12e", "1a3.14", "1,2,3", "+-5", "12e+4.3"都不是


// 分析:
// 判断第一个字符是不是整数
// 1) 是; 在字符串上移动一个字符, 继续扫描剩余字符串0~9的数位
// 2) 不是; 直接判断0~9的数位
// 如果是小数, 将遇上小数点
// 如果是可惜计数法, 在整数或者小数的后面还有可能遇到'e'或者'E'

#include <iostream>
#include <string>

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
    bool isNumeric(char* str) {
        if(str == NULL) {
            return false;
        }

        // 判断是否遇见符号+ / -
        if(*str == '+' || *str == '-') {
            ++str;
        }
        if(*str == '\0') {
            return false;
        }

        bool numberic = true;

        ScanDigits(&str);

        if(*str != '\0') {
            if(*str == '.') {                   // 小数后面有指数
                ++str;
                ScanDigits(&str);

                if(*str == 'e' || *str == 'E') {
                    numberic = IsExponential(&str);
                }
            }
            else if(*str == 'e' || *str == 'E') {       // 指数判断
                numberic = IsExponential(&str);
            }
            else {
                numberic = false;
            }
        }
        return numberic && *str == '\0';

    }

    void ScanDigits(char **str) {
        while(**str != '\0' && (**str >= '0' && **str <= '9')) {
            ++(*str);
        }
    }

    bool IsExponential(char **str) {
        if(**str != 'e' && **str != 'E') {
            return false;
        }
        ++(*str);

        if(**str == '+' || **str == '-') {
            ++(*str);
        }
        if(**str == '\0') {
            return false;
        }
        ScanDigits(str);

        return (**str == '\0') ? true : false;
    }
};

int __tmain() {
    Solution solu;

    cout << solu.isNumeric("1a234") <<endl;
    cout << solu.isNumeric("1e234") <<endl;
    cout << solu.isNumeric("1.234") <<endl;
    cout << solu.isNumeric("-E234") <<endl;
    cout << solu.isNumeric("12e5.6") <<endl;
    cout << solu.isNumeric("12e") <<endl;

    return 0;
}
