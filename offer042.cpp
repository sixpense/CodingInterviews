// 042-左旋转字符串
// 汇编语言中有一种移位指令叫做循环左移
// 对于一个给定的字符序列S, 输出循环左移K位后的序列输出
// Input: "abcXYZdef"
// Output: "XYZdefabc"


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
    string LeftRotateString(string str, int n) {
        if(str.size() == 0) {
            return "";
        }

        // res[i] = str[(i + n) % str.size()];
        // res[(i - n + str.size()) % str.size()] = str[i];

        string res(str);
        if(n > str.size()) {
            n %= str.size();
        }

        debug <<"length = " <<str.size() <<", n = " <<n <<endl;
        for(int i = 0; i < str.size(); i++) {
            debug <<"i = " <<i <<", origin = " <<((i + n) % str.size()) <<endl;
            res[i] = str[(i + n) % str.size()];
        }
        return res;
    }
    string Reverse(string str) {
        int left = 0, right = str.size() - 1;
        while(left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }
        return str;
    }
};


// 新串是string+string
// n + string 是新串的子串

class Solution_1 {
public:
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if(length == 0) {
            return "";
        }
        n = n % length;
        str += str;

        return str.substr(n, length);
    }
};

// 通过翻转直线循环移位
// reverse(0, i - 1)
// reverse(i, n - 1)
// reverse(0, n - 1)

class Solution_2 {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0) {
            return "";
        }
        n %= str.size();

        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size() - 1);
        Reverse(str, 0, str.size() - 1);

        return str;
    }

    void Reverse(string &str, int left, int right) {
        while(left < right) {
            swap(str[left], str[right]);
            
            left++;
            right--;
        }
    }
};



int __tmain() {
    Solution solu;
    cout <<solu.LeftRotateString("abcDHJjie", 3) <<endl;

    return 0;
}
