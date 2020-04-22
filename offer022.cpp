// 022-栈的压入弹出序列
// 输入两个整数序列,第一个序列表示栈的压入顺序,
// 请判定第二个序列是否为该栈的弹出顺序.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if(pushV.size() == 0 || popV.size() == 0) {
            return false;
        }
        stack<int> s;
        int push, pop;

        s.push(pushV[0]);
        debug <<"push" <<pushV[0] <<endl;

        for(push = 0, pop = 0; push < pushV.size() && pop < popV.size();) {
            if(s.empty() != true && s.top() == popV[pop]) {
                debug <<"pop"<<popV[pop] <<endl;
                s.pop();
                pop++;
            }
            else {
                s.push(pushV[++push]);
                debug <<"push" <<pushV[push] <<endl;
            }
        }
        if(s.empty() == true) {
            return true;
        }
        else {
            return false;
        }
    }
};

int __tmain() {
    int nPush[5] = {1, 2, 3, 4, 5};
    int nPop1[5] = {4, 5, 3, 2, 1};
    int nPop2[5] = {4, 3, 5, 1, 2};
    int nPop3[5] = {5, 4, 3, 2, 1};
    int nPop4[5] = {4, 5, 2, 3, 1};

    Solution solu;

    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) << endl;
    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) << endl;
    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) << endl;
    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) << endl;

    return 0;
}

class Solution_1 {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if(pushV.size() == 0 || popV.size() == 0) {
            return false;
        }
        int top = -1, pop = 0, pop = 0;

        ++top;
        debug <<"push" <<pushV[top] <<endl;

        while(push < pushV.size() && pop < popV.size()) {
            if(top != -1 && pushV[top] == popV[pop]) {
                debug <<"pop" <<popV[pop] <<endl;
                top--;
                pop++;
            }
            else {
                pushv[++top] = pushV[++push];
                debug <<"push" <<pushV[push] <<endl;

            }
        }
        debug <<top <<push <<pop <<endl;
        return (top == -1);
    }
}
