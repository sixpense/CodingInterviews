// 054-字符流中第一个不重复的字符
// 请实现一个函数用来查找第一个不重复的字符.
// 例如: "go"中第一个不重复的字符是:"g"
// "google"中第一个不重复的字符是: "o".

#include <iostream>
#include <cstring>

// 相当于一个在线算法, 要求能对一个源源不断的输入流进行处理
// 字符只能一个接着一个从字符流中读取出来, 需要定义一个数据容器来保存字符在字符流中的位置.

using namespce std;

class Solution {
public:
    Solution() {
        str = "";
        menset(count, '\0', sizeof(count));
    }

    // Insert one char from stringstream
    void Insert(char ch) {
        str += ch;
        count[(int)ch]++;
    }

    // Return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int len = str.size();

        for(int i = 0; i < len; i++) {
            if(count[(int)str[i]] == 1) {
                return str[i];
            }
        }

        return '#';
    }

private:
    string str;
    int    count[256];
};
