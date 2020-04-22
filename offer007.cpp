// 007用两个栈来实现队列

#include <iostream>
#include <stack>

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
    void push(int node) {
        stackIn.push(node);
    }

    int pop() {
        int node = -1;

        //如果两个栈都是空的时候
        if(this->empty() == true) {
            debug <<"整个队列为空" <<endl;
            return -1;
        }
        else {
            // 否则队列中有元素
            // 当输出栈不为空时,直接输出元素
            // 当输出栈为空时,但输入栈不为空,需要将输入栈的元素全部倒入输出栈
            if(stackOut.empty() == true) {
                // 输出栈为空
                while(stackIn.empty() != true) {
                    node = stackIn.top();
                    stackIn.pop();
                    stackOut.push(node);
                    debug <<node <<"倒入输出栈" <<endl;
                }
            }

            node = stackOut.top();
            stackOut.pop();

            debug <<"---------队头元素:" <<node <<endl;
        }
        return node;
    }

    bool empty() {
        return (stackIn.empty() == true && stackOut.empty() == true);
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;

};

int __tmain() {
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    int node;
    while(solu.empty() != true) {
        cout <<solu.pop();
    }
    return 0;
}
