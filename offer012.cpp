// 012-打印1到最大的N位数


#include <iostream>
#include <cstring>

using namespace std;

#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {
public:
    Solution(int n) {
        this->m_N = n;
        this->m_isOverFlow = false;

        this->m_number = new char[n + 1];
        memset(m_number, '\0', n + 1);
        this->m_number[n-1] = '1';
        this->m_length = 1;
    }

    void Print() {
        if(m_N <= 0) {
            return;
        }
        while(this->m_isOverFlow != true) {
            PrintNumber();
            Increment();
        }
    }

    void PrintNumber() {
        debug <<"number is stroge in [" <<m_N - m_length <<", " <<m_N <<"]" <<endl;
        for(int i = m_N - m_length; i < m_N; i++) {
            cout<<m_number[i];
        }
        cout<<endl;
    }

    bool Increment() {
        int nSum = 0;           //当前位
        int takeOver = 0;       //进位
        for(int i = m_N - 1; i >= m_N - m_length; i--) {
            if(m_number[i] != '\0') {
                nSum = m_number[i] - '0' + takeOver;
            }
            else {
                nSum = 0;
            }

            nSum++;
            debug <<"nSum = " <<nSum <<endl;

            if(nSum >= 10) {            // 需要进位
                if(i == 0) {            // 溢出
                    m_isOverFlow = true;
                    debug <<"Over Flow now." <<endl;
                    delete m_number;
                }
                else {
                    nSum -= 10;
                    m_number[i] = '0' + nSum;

                    takeOver = 1;
                    if(i == m_N - m_length) {
                        m_length++;
                        debug <<"take over now ( length = )" <<m_length <<")";
                    }
                }
            }
            else {
                if(takeOver == 1) {
                    debug <<"it's a take over" <<endl;
                }
                m_number[i] = '0' + nSum;
                break;
            }
        }
        return 0;
    }

private:
    int m_N;            //N位数
    char *m_number;     //存储数据的字符串
    bool m_isOverFlow;  //是否溢出
    volatile int m_length;  //当前数字的位数

};

int __tmain() {
    int n;
    while(cin >> n) {
        Solution solu(n);
        solu.Print();
    }
    return 0;
}
