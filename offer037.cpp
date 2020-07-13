// 037-两个列表的第一个公共结点


#include <iostream>

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

#ifdef __tmain

struct ListNode {
public:
    int val;
    struct ListNode *next;
};

#endif

// 暴力方法
// 对于第一链表的每个节点, 依次判断是不是第二条链表的公共节点

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode, *rightHead) {
        ListNode *left = NULL;
        ListNode *right = NULL;

        for(left = leftHead; left != NULL; left = left->next) {
            debug <<endl <<left->val <<" : ";

            for(right = rightHead; right != NULL; right = right->next) {
                debug <<right->val <<", ";
                if(left == right) {
                    break;
                }
            }
            debug <<right->val <<", ";
            if(left == right) {
                break;
            }
        }
        return left;
    }
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead) {
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        int leftLength = 0;
        int rightLength = 0;

        leftLength = GetListLength(left);
        rightLength = GetListLength(right);

        int length = 0;


        //对其两个链表
        if(leftLength < rightLength) {
            length = rightLength- leftLength;
            while(right != NULL && length > 0) {
                right = right->next;
                length--;
            }
        }
        else {
            //左链表长
            length = leftLength - rightLength;
            while(left != NULL && length > 0) {
                left = left->next;
                length--;
            }
        }


        while(left != NULL && right != NULL) {
            if(left == right) {
                break;
            }

            left = left->next;
            right = right->next;
        }
        return ((left == right) ? left : NULL);
    }

    int GetListLength(ListNode *head) {
        ListNode *node = head;
        int length = 0;
        while(node != NULL) {
            length++;
            node = node->next;
        }
        return length;
    }
};

// 将两个链表拼接起来实现右对齐
class Solution_4 {
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead) {
        listNode *left = leftHead;
        ListNode *right = rightHead;

        debug <<(left == NULL ? -1 : left->val) <<", ";
        debug <<(right == NULL ? -1 : right->val) <<endl;

        while(left != right) { // 判断链表是否都为空
            left = (left == NULL ? rightHead : left->next);
            right = (right == NULL ? leftHead : right->next);

        }
        return left;
    }
}

// 利用栈后进先出的特性, 栈顶元素一定是最后一个元素, 从而两个链表是右对齐.
class Solution_5 {
public:
    ListNode* FindFirstCommonNode(ListNode * leftHead, ListNode *rightHead) {
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        stack<ListNode *> leftStack;
        stack<ListNode *> rightStack;

        // 节点依次入栈
        while(left != NULL) {
            leftStack.push(left);
            left = left->next;
        }
        while(right != NULL) {
            rightStack.push(right);
            right = right->next;
        }

        // 开始同步弹出元素
        while(leftStack.empty() != true && rightStack.empty() != true) {
            left = leftStack.top();
            right = rightStack.top();

            debug <<left->val <<", " <<right->val <<endl;

            if(left != right) {
                break;
            }
            leftStack.pop();
            rightStack.pop();
        }
        if(left != right) {
            return left->next;
        }
        else {
            return NULL;
        }
    }
};

int __tmian() {
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode left[3];
    left[0].val = 1;
    left[0].next = &left[1];
    left[1].val = 2;
    left[1].next = &left[2];
    left[2].val = 3;
    left[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    Solution solu;
    ListNode *node = solu.FindFirstCommonNode(left, right);
    while(node != NULL) {
        debug <<node->val <<" ";
        node = node->next;
    }
    debug <<endl;

    return 0;
}

