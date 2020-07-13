// 045-孩子们的游戏
// 圆圈中最后的数

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// 调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

// 使用模拟环形列表

class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m) {
        if(n < 1 || m < 1) {
            return -1;
        }
        vector<int> numbers;

        for(int i = 0; i < n; i++) {
            numbers.push_back(i);
            debug <<i <<" ";
        }
        debug <<endl;

        unsigned int cntN = 0;
        unsigned int cntM = -1;
        while(numbers.size() > 1) {
            debug <<"count = " <<1 <<", num[" << cntN <<"] = " <<numbers[cntN] <<endl;
            for(int cntM = 1; cntM < m; cntM++) {
                ++cntN;
                cntN %= numbers.size();
                debug << "count = " <<cntN + 1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;

            }
            debug <<numbers[cntN] <<" leave the list" <<endl;
            numbers.erase(numbers.begin() + cntN);
#ifdef debug
            copy(numbers.begin(), numbers.end(), ostream_iterator< int >(cout, " "));
            debug <<endl;
#endif
        }
        debug <<"count = " <<1 <<", num[" <<cntN <<"] = " <<numbers[cntN] <<endl;
        return numbers[0];
    }
};

class Solution_1 {
    // 使用递推公式, 获取最后胜利者的序号
    // F[1] = 0;
    // F[i] = (F[i - 1] + m ) mod i; 其中m是位移量
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m) {
        if(n < 1 || m < 1) {
            return -1;
        }

        int last = 0;
        debug <<"F[" <<0 <<"] = " <<last <<endl;

        for(int step = 2; step <= n; step++) {
            last = (last + m) % step;
            debug <<"F[" <<step - 1 <<"] = " <<last <<endl;
        }
        return last;
    }
};

class Solution_2 {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m) {
        if(n < 1 || m < 1) {
            return -1;
        }
        else if( n == 1 ) {
            return 0;
        }
        else {
            return (LastRemaining_Solution(n - 1, m) + m) % n;
        }
    }
};

int __tmain() {
    Solution solu;

    cout <<solu.LastRemaining_Solution(5, 2) <<endl;

    return 0;
}
