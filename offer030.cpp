// 030 寻找最小的K个数
// 输入n个整数, 找出其中最小的K个数

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;



#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

class Solution {

protected:
    vector<int> m_res;

public:
    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k) {
        m_res.clear();

        if(numbers.size() == 0 || numbers.size() < k) {
            return m_res;
        }
        LeastKNumbers_ByCountSort(numbers, k);

        return m_res;
    }
    // 排序后输出前K个数字
    vector<int> LeastKNumbers_BySort(vector<int> numbers, int k) {
        debug <<endl <<"line" <<__LINE__ <<"in function: " <<__func__ <<endl <<endl;

        sort(numbers.begin(), numbers.end());

        for(int i = 0; i < k; i++) {
            debug <<numbers[i] << "";
            m_res.push_back(numbers[i]);
        }
        debug <<endl;

        return m_res;
    }

    // 采用选择排序, K趟找出前K个数字
    // 选择排序没趟结束后前i个数字都有序, 因此K趟可以找出前K小的数字
    vector<int> LeastKNumbers_BySelectSort(vector<int> numbers, int k) {
        debug <<endl <<"line " <<__LINE__ << " in funciton :"<<__func__ <<endl <<endl;

        int i, j, index;
        int length = numbers.size() - 1;
        for( i = 0; i < k; i++ ) {
            index = i;
            for(j = i + 1; j < length; j++) {
                if(numbers[j] < numbers[index]) {
                    index = j;
                }
            }
            if(index != 1) {
                swap(numbers[i], numbers[j]);
            }
            m_res.push_back(numbers[i]);
        }
        return m_res;
    }

    // 采用冒泡排序法
    vector<int> LeastKNumbers_ByBubbleSort(vector<int> numbers, int k) {
        debug << endl <<"line " << __LINE__ <<" in function : " << __func__ <<endl <<endl;

        int i, j;
        int length = numbers.size();
        for(i = 0; i < k; i++) {
            for(j = length - i - 1; j > 0; j--) {
                if(numbers[j - 1] > numbers[j]) {
                    swap(numbers[j - 1], numbers[j]);
                }
            }
            m_res.push_back(numbers[i]);
        }
        return m_res;
    }

    // 采用计数排序
    vector<int> LeastKNumbers_ByCountSort(vector<int> numbers, int k) {
        int i, count;
        int num[1000];
        memset(num, '\0', 1000);

        for(i = 0; i < numbers.size(); i++) {
            int i, count;
            int num[1000];
            memset(num, '\0', 1000);
        }

        for(i = 0; i < numbers.size(); i++) {
            num[numbers[i]]++;
            debug <<numbers[i] <<endl;
        }
        for(i = 0, count = 0; i < 1000 && count < k; i++) {
            if(num[i] != 0) {
                count++;
                debug <<i <<" ";
                m_res.push_back(i);
            }
        }
        return m_res;
    }

    vector<int> GetLeastNumbers_ByFindKth(vector<int> numbers, int k) {
        int kth;
        vector<int> res;

        for(int i = 0; i < k; i++) {
            kth = FindKth(numbers, 0, numbers.size() - 1, i);
            res.push_back(kth);
        }

        return res;
    }

    /*
     * [Partition] 快速排序的划分函数, 返回枢轴在排序的数组中应该所处的位置
     * @param       numbers             [待划分的数组]
     * @param       left                [待划分数据的起始位置]
     * @param       right               [待划分数据的结束位置]
     * @return                          [返回枢轴在排序后数组中应该所处的位置]
     */
    int Partition(vector<int> &numbers, int left, int right) {
        int i = left, j = right;
        int pivotIndex = left, pivotNum = numbers[pivotIndex];

        debug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j) {
            while(i < j && numbers[j] >= pivotNum) {
                debug << "[ "<< i <<", "<< j <<" ]" <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
            }
            debug <<"now we find i = " <<i <<", posJ = " <<j <<", num = "<<numbers[j] <<" < " << pivotNum <<endl;
            numbers[i] = numbers[j];

            while(i < j && numbers[i] <= pivotNum) {
                debug <<"[" <<i <<", " <<j <<"]" <<numbers[i] << " <= " <<pivotNum <<endl;
                i++;
            }
            debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum;
            numbers[j] = numbers[i];
        }
        numbers[i] = pivotNum;
        return i;
    }

    /* 
     * [FindKth] 查找数组中第K大的元素
     * @param       numbers             [待查找元素所在的数组]
     * @param       left                [数据起始元素的位置]
     * @param       right               [数据终止元素的位置]
     * @param       k                   [第K大的元素]
     * @return                          [返回数组中第K大的元素的值]
     */
    int FindKth(vector<int> &numbers, int left, int right, int k) {
        int res;
        int pivotIndex = left + 1;

        if(left == right) {
            debug <<"left == right" <<numbers[left] <<endl;
            return numbers[left];
        }

        pivotIndex = Partition(numbers, left, right);

        if(pivotIndex < k) {
            debug <<"K is in [" <<pivotIndex + 1 <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex+1, right, k);
        }
        else if(pivotIndex > k) {
            debug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
            return numbers[pivotIndex];
        }
        else {
            return numbers[pivotIndex];
        }
    }

    /* 
     * [CheckMoerThanHalf] 检查Num元素在数组numbers中出现的次数是否超过一半
     * @param       numbers             [待处理的数组]
     * @param       num                 [待查询的元素]
     * @return                          [如果元素num在数组numbers中出现的次数超过一半则返回true]
     */
    bool CheckMoerThanHalf(vector<int> numbers, int num) {
        int count = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == num) {
                count++;
            }
        }
        debug <<"num = " <<num <<", count = " <<count <<endl;

        if(count > numbers.size() / 2) {
            return true;
        }
        else {
            return false;
        }
    }

    class greater_class {
    public:
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    vector<int> GetLeastNumbers_solution(vector<int> numbers, int k) {
        return LeastKNumbers_ByMinHeap(numbers, k);
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k) {
        vector<int> res;

        if(numbers.size() == 0 || numbers.size() < k) {
            return res;
        }
        make_heap(numbers.begin(), numbers.end(), greater_class());

        for(int i = 0; i < k; i++) {
            debug <<numbers[0] <<" ";
            res.push_back(numbers[0]);

            pop_heap(numbers.begin(), numbers.end(), greater_class());
            numbers.pop_back();
        }
        return res;
    }
};

int __tmain() {
    int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
