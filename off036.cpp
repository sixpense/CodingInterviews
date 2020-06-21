// 036-数组中逆序对
// 在数组中的两个数字, 如果前面一个数字大于后面的数字, 则这两个数字组成一个逆序对.
// 输入一个数组, 求出这个逆序对的总数.

#include <iostream>
#include <vector>

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

// 暴力解法
class Solution {
public:
    int InversePairs(vector<int> elem) {
        if(elem.size() == 0) {
            return 0;
        }

        int count = 0;
        for(unsigned int i = 0; i < elem.size(); i++) {
            for(unsigned int j = i + 1; j < elem.size(); j++) {
                if(elem[i] > elem[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

// 冒泡排序
class Solution_1 {
public:
    int InversePairs(vector<int> elem) {
        if(elem.size() == 0) {
            return 0;
        }

        return BubbleSort(elem);
    }

    int BubbleSort(vector<int> elem) {
        bool flag = true;
        int count = 0;
        unsigned int length = elem.size();

        for(unsigned int i = 0; i < length - 1 && flag == true; i++) {
            flag = false;
            for(unsigned int j = 0; j < length - i - 1; j++) {
                if(elem[j] > elem[j + 1]) {
                    swap(elem[j], elem[j+1]);
                    flag = true;
                    count++;
                }
            }
        }
        return count;
    }
};

// 分治算法
class Solution_2 {
public:
    int InversePairs(vector<int> elem) {
        if(elem.size() == 0) {
            return 0;
        }
        vector<int> temp(elem.size());
        int count = InversePairsCore(elem, 0, elem.size() - 1, temp);

        return count;
    }

    int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp) {
        int i = mid;
        int j = end;
        int k = 0;
        int count = 0;
        // 设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
        while(i >= start && j > mid) {
            if(elem[i] > elem[j]) {
                temp[k++] = elem[i--];
                count += j - mid;
            }
            else {
                temp[k++] = elem[j--];
            }
        }
        while(i >= start) {
            temp[k++] = elem[i--];
        }
        while(j > mid) {
            temp[k++] = elem[j--];
        }

        for(i = 0; i < k; i++) {
            elem[end - i] = temp[i];
        }

        copy(elem.begin(), elem.end(), ostream_iterator<int>(cout, " "));
        return count;
    }

    int InversePairsCore(vector<int> &elem, int start, int end, vector<int> &temp) {
        int Inversions = 0;
        if(start < end) {
            int mid = (start + end) / 2;
            inversions += InversePairsCore(elem, start, mid, temp);
            inversions += InversePairsCore(elem, mid + 1, end, temp);
            Inversions += MergeElem(elem, start, mid, end, temp);
        }
        return Inversions;
    }
};

int __tmain() {
    Solution solu;
    int arr[] = {7, 5, 6, 4};
    vector<int> vec(arr, arr+4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
