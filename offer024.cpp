// 024-二叉搜索树的后序遍历序列
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。假设输入的数组的任意
// 两个数字互不相同。

#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

#define undebug 0&& cout

#ifdef __tmain


#endif



// 暴力实现

class Solution_1 {
public:
    bool VerifySquenceOfBST_Iterratively(const vector<int>& sequence) {
        int left = 0, right = sequence.size() - 1;
        while(left < right && right != 0) {
            while(sequence[left] < sequence[right])
                left++;
            while(sequence[left] > sequence[right])
                left++;

            if(left < right)
                return false;

            left = 0;

            right--;
        }
        return (right == 0) ? true : false;
    }
};

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) {
            return false;
        }
        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int> &sequence, int left, int right) {
        if(left >= right) {
            return true;
        }

        int mid = right - 1;
        while(sequence[mid] > sequence[right]) {
            mid--;
        }

        int i = left;
        while(i < mid && sequence[i] < sequence[right]) {
            i++;
        }
        if(i < mid) {
            return false;
        }
#ifdef __tmain
        printf("left : ");
        for(int i = left; i <= mid; i++) {
            cout << sequence[i] << " ";
        }
        cout <<endl;
        printf("right : ");
        for(int i = mid + 1; i < right; i++) {
            cout << sequence[i] << " ";
        }
        cout <<endl;
        cout <<"root: " <<sequence[right] <<endl;
#endif 
        return judge(sequence, left, mid) && judge(sequence, mid + 1, right - 1);
    }
};

int __tmain() {
    int a[] = {2, 9, 5, 16, 17, 15, 19, 18, 12};
    vector<int> vec(a, a+9);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec);
    return 0;
}
