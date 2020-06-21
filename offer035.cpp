// 035-第一个只出现一次的字符位置
// 从一个字符串(1 <= 字符串长度 <= 1000, 全部由字母组成)中找到第一个只出现一次的那个字符.
// 若为空串, 返回-1. 位置索引从0开始.

#include <iostream>

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
 
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0) {
            return -1;
        }
        unsigned int length = str.length();
        unsigned int i, j;
        bool flag = true;
        for(i = 0; i < length; i++) {
            flag = true;
            if(str[i] == '\0') {
                continue;
            }
            debug << "str[" <<setfill('0') <<setw(2) <<i <<"] = " <<str[i] <<endl;

            for(j = i + 1; j < length; j++){
                debug <<"str[" <<i <<"] = " <<str[i] <<", ";
                debug <<"str[" <<j <<"] = " <<str[j] <<endl;

                if(str[j] == '\0') {
                    continue;
                }
                else if(str[i] == str[j]) {
                    debug <<str[i] <<str[j] <<endl;
                    str[j] = '\0';
                    flag = false;
                }
            }
            if(flag == true) {
                return i;
            }
        }
        return -1;
    }
};

class Solution_1 {
protected:
    int count[256];
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0) {
            return -1;
        }
        unsigned int i;
        memset(count, '\0', sizeof(count));

        for(i = 0; i < str.length(); i++) {
            debug <<(unsigned int)str[i] <<endl;
            count[(unsigned int)str[i]]++;
        }

        for(i = 0; i < str.length(); i++) {
            debug <<str[i] <<", " <<count[(unsigned int)str[i]] <<endl;
            if(count[(unsigned int)str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
