// 016-反转链表


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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pReversedHead = NULL;
        ListNode *pNode = pHead;
        ListNode *pPrev = NULL;
        ListNode *pNext = NULL;

        while(pNode != NULL) {
            pNext = pNode->next;        //保存下一个节点

            pNode->next = pPrev;        //指针指向反转

            pPrev = pNode;              //保存前一个指针

            pNode = pNext;              //递增指针,指向下一个结点
        }
        return pPrev;
    }
};

int __tmain() {
    ListNode list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;

    ListNode *node = list;
    while(node != NULL) {
        cout <<node->val <<" ";
        node = node->next;
    }
    cout <<endl;

    Solution solu;
    node = solu.ReverseList(list);
    while(node != NULL) {
        cout <<node->val <<" ";
        node = node->next;
    }
    cout <<endl;

    return 0;

}
