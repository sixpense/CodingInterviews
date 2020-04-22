// 017-合并两个排序的列表


#include <iostream>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 & cout

#endif

#ifdef __tmain
struct ListNode {
public:
    int val;
    struct ListNode *next;
};

#endif

class Solution {
public:
    ListNode* Merge(ListNode *pLeft, ListNode *pRight) {
        if(pLeft == NULL) {
            debug <<"left list is NULL" <<endl;
            return pRight;
        }
        else if(pRight == NULL) {
            debug <<"right list is NULL" <<endl;
            return pLeft;
        }

        ListNode *left = pLeft;
        ListNode *right = pRight;

        ListNode *head = NULL;
        if(left->val < right->val) {
            head = left;
            left = left->next;
            debug <<head->val <<"is list" <<endl;
        }
        else {
            head = right;
            right = right->next;
            debug <<head->val <<"in list" <<endl;
        }

        //遍历两个列表
        ListNode *curr = head;

        while(left != NULL && right != NULL) {
            debug <<"left = " <<left->val <<", right = " <<right->val <<endl;

            if(left->val < right->val) {
                debug <<left->val <<"in list" <<endl;

                curr->next = left;
                curr = curr->next;

                left = left->next;
            }
            else {
                debug <<right->val <<"in list" <<endl;

                curr->next = right;
                curr = curr->next;

                right = right->next;
            }
        }

        // 处理较长链表的剩余部分
        if(left != NULL) {
            curr->next = left;
        }
        else {
            curr->next = right;
        }
        return head;
    }
};

int __tmain() {
    ListNode left, right[3];

    left.val = 5;
    left.next = NULL;

    right[0].val = 1;
    right[0].next = &right[1];
    right[1].val = 2;
    right[1].next = &right[2];  
    right[2].val = 3;
    right[2].next = NULL;

    Solution solu;
    ListNode *head = solu.Merge(&left, right);
    while(head != NULL) {
        cout <<head->val;
        head = head->next;
    }
    return 0;
}
