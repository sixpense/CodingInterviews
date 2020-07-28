/*
 * 057-删除链表中重复的节点
 * 在一个排序的链表中, 存在重复的节点, 请删除改链表中重复的节点, 返回链表头指针.
 * 例如: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 */

#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#ifdef __tmain

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x = 0): val(x), next(NULL) {

    }
};

#endif

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        // 设置一个trick, 作为头指针
        ListNode *first = new ListNode(-1);

        first->next = pHead;

        ListNode *p = pHead;
        ListNode *last = first;

        while(p != NULL && p->next != NULL) {
            debug <<p->val <<endl;

            if(p->val == p->next->val) {
                // 跳过所有重复的数字
                int val = p->val;
                while(p!= NULL && p->val ==val) {
                    p = p->next;
                }

                // 此时p指向了非重复的第一个元素, 设置last->next = p
                // 此时p-val也可能是重复的, 因此不可以设置last = p, 而是重新进入循环
                last->next = p;
            }
            else {
                last = p;
                p = p->next;
            }
        }
        return first->next;
    }
};

int __tmain() {
Solution solu;

    ListNode list[7];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 3;
    list[3].next = &list[4];

    list[4].val = 4;
    list[4].next = &list[5];

    list[5].val = 4;
    list[5].next = &list[6];

    list[6].val = 5;
    list[6].next = NULL;

    ListNode *node = solu.deleteDuplication(list);

    while(node != NULL) {
        cout <<node->val <<"->";
        node = node->next;
    }
    return 0;
}
