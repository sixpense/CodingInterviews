// 033-把数组排成最小的数
// 输入一个正整数数组, 把数组里所有的数字拼接起来排成一个数, 答应能凭借出来的所欲数字中最小
// 的一个, 例如输入{3, 32, 321}, 输出[321323]

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

template<class T>
string ToString(const T& t) {
    ostringstream oss;          // 创建一个流

    oss <<t;                    // 把值传递到流中
    return oss.str();           // 获取装换后的字符并将其写入result
}

class Solution {
public:
    static bool Compare(const string &left, const string &right) {
        string leftright = left + right;
        string rightleft = right + left;
        if(leftright > rightleft) {
            debug << leftright <<" > " <<rightleft <<" -- " <<endl;
        }
        else {
            debug << leftright <<" < " <<rightleft <<" -- " <<endl;
        }

        return leftright < rightleft;
    }

    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        string str;

        vector<string> strNum;

        // 将整数装换成字符串
        for(unsigned int i = 0; i < numbers.size(); i++) {
            str = ToString(numbers[i]);
            strNum.push_back(str);
            debug <<str <<endl;
        }

        // 对字符串按照拼接后的大小进行排序
        sort(strNum.begin(), strNum.end(), Compare);

        // 拼接结果
        for(unsigned int i = 0; i < strNum.size(); i++) {
            debug <<strNum[i];
            res += strNum[i];
        }
        debug <<endl;
        return res;
    }
};

int __tmain() {
    Solution solu;
    int arr[] = {321, 32, 3};
    vector<int> vec(arr, arr+3);
    cout <<solu.PrintMinNumber(vec) <<endl;
    return 0;
}
