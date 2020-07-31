/*
 * 064-数据流之中的中位数
 * 如何得出一个数据流中的中位数?
 * 如果从数据流中读出奇数个数值, 那么中位数就是所有数值排序之后位于中间的数值, 如果从数据流
 * 中读出偶数个数值, 那么中位数就是所有数值排序之后中间两个数的平均值.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

// 使用堆排序策略
class Solution {
protected:
    vector<int> m_min;          //数组中后一半元素组成的最小化堆
    vector<int> m_max;          //数组中前一半元素组成的最大化堆

public:
    /*
     * 将元素插入堆中, 为了保证数据平均的分配到两个堆中, 两个堆的数据数目之差不能超过1.
     * 插入的元素会影响两个堆的平衡, 因此两个堆都必须调整.
     * 0 <= m_min.size() - m_max.size() < 1;
     */
    void Insert(int num) {
        if(((m_min.size() + m_max.size()) & 1) == 0) {
            /*
             * 偶数数据的情况下, 直接将新的数据插入到数组的后半段, 即在最小堆中插入元素.
             * 测试最小堆中多出一个元素, 即最小元素, 将其弹出, 压入前半段(最大堆中).
             */
            if(m_max.size() > 0 && num < m_max[0]) {
                m_max.push_back(num);
                push_heap(m_max.begin(), m_max.end(), less<int>()); //对刚插入的元素做堆排序, 最大元素放在第一个

                num = m_max[0];
                pop_heap(m_max.begin(), m_max.end(), less<int>()); //将front(第一个最大元素)移动到end的前部, 将剩下的元素重新构造一个新的heap
                m_max.pop_back();
            }
            m_min.push_back(num);           //把前一半找到的最大值放入到后一半中
            push_heap(m_min.begin(), m_min.end(), greater<int>());
        }
        else {
            /* 否则数组中元素是奇数
             */
            if(m_min.size() > 0 && num > m_min[0]) {
                m_min.push_back(num);
                push_heap(m_min.begin(), m_min.end(), greater<int>());//小顶堆
                num = m_min[0];
                pop_heap(m_min.begin(), m_min.end(), greater<int>());
                m_min.pop_back();
            }
            m_max.push_back(num);
            push_heap(m_max.begin(), m_max.end(), less<int>());
        }
    }
    /* 由于假定, 0 <= m_min.size() = m_max.size() <= 1
     * 当总元素个数为偶数时, 中位数即(m_max[0] + m_min[0]) / 2
     * 当总元素个数为奇数时, 中位数即m_min[0];
     */
    double GetMedian() {
        int size = m_min.size() + m_max.size();
        if(size == 0) {
            return -1;
        }
        double median = 0;
        if((size & 1) != 0) {
            median = (double) m_min[0];
        }
        else {
            median = (double) (m_max[0] + m_min[0]) / 2;
        }
        return median;
    }
};

class Solution_Set_Multiset {
protected:
    multiset<int> left;// 左半部分
    multiset<int> right;// 右半部分
public:
    void Insert(int n) {
        int tmp = n;
        if(((left.size() + right.size()) & 1) == 0) {
            if(right.empty() != true && n > *right.begin()) {
                right.insert(n);
                tmp = *right.begin();
                right.erase(right.find(tmp));
            }
            left.insert(tmp);
        }
        else {
            if(left.empty != true && n < *left.rbegin()) {
                left.insert(n);
                tmp = *left.rbegin();
                left.erase(left.find(tmp));
            }
            right.insert(tmp);
        }
    }
    double GetMedian() {
        if(((left.size() + right.size()) & 1) == 0) {
            return (double)(*left.rbegin() + *right.begin()) / 2.0;
        }
        else {
            return (double)*left.rbegin();
        }
    }
};

int __tmain() {
    Solution s;
    int array[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    vector<int> vec(array, array + 9);

    for(int i = 0; i < vec.size(); i++) {
        s.Insert(vec[i]);
        cout <<s.GetMedian() <<endl;
        return 0;
    }
}
