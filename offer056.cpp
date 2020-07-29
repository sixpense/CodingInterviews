/*
 * 056-链表中环的入口节点
 * 根据之前的题目: 查找链表中倒数第K个节点
 * 假设链表长度为N, 那么第N个节点的链接到了第K个节点形成了环, 我们需要查找倒数第N-K-1个节点
 * 定义两个指针P1, P2指向链表的头部, 指针P1在链表中先走N-K-1步, 然后两个指针同步向前移动,
 * 两个指针会相遇在环入口处.
 * 那如何得到环中节点的数目呢?
 * 使用快慢指针, 如果快指针追上了慢指针, 说明链表存在环.
 * 相遇的位置一定在环内, 通过计算环的长度, 最后找到环的入口地址.
 * 1) 找到环中相汇点. 分别用P1, P2指向链表头部, P1每走一步, P2走两步, 直到P1 == P2找到环中
 * 相汇点.
 * 2) 找环的长度. 从环中相汇点开始, P1不动, P2前移. 当再次相遇, P2刚好绕环一周, 移动的距离
 * 为环的长度.
 * 3) 求环的起点. 转换为求环的倒数第N-K个节点. 两指针left, right指向起始, right先走K步, 然
 * 后两指针同步移动, 当两指针再次相遇, right指针刚好绕环一周回到环起点, left刚好走到环起点.
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

struct ListNode
{
    int val;
    struct ListNode *next;
};


#endif // __tmain

#define SLOW_STEP   1
#define FAST_STEP   2

class Solution {
public:
    /*
     * 如果链表中有环, 则返回环中的任意一个节点
     */
    ListNode* HasCycle(ListNode *pHead) {
        if(pHead == NULL) {
            return NULL;
        }

        ListNode *pSlow = pHead->next;
        ListNode *pFast = pHead->next;
        while(pSlow != NULL && pFast != NULL) {
            if(pFast ==pSlow) {
                return pSlow;
            }
            pSlow = NextNode(pSlow, 1);
            pFast = NextNode(pFast, 2);
        }
        return NULL;
    }

    ListNode* NextNode(ListNode *node, int step) {
        for(int i = 0; i < step && node != NULL; i++) {
            node = node->next;
        }
        return node;
    }

    // 获取到链表中环的长度
    int GetCycleLength(ListNode *node) {
        int length = 0;
        if(node == NULL) {
            return length;
        }

        // 环内循环, 从任意一个节点再回到这个节点的距离就是环的长度
        ListNode *currNode = node;
        ListNode *stepNode = node->next;
        for(length = 1; ; length++) {
            if(stepNode == currNode) {
                return length;
            }
            stepNode = stepNode->next;
        }
        return 0;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        // 先找到链表环中的某一个节点
        ListNode* meetingNode = HasCycle(pHead);
        if(meetingNode == NULL) {
            return NULL;
        }

        debug <<"a node in cycle " <<meetingNode->val <<endl;

        // 获取到链表中环路的长度
        int cycleLength = GetCycleLength(meetingNode);
        debug <<"cycle length = " <<cycleLength <<endl;

        // 找到链表中环的入口
        ListNode *leftNode = pHead;
        ListNode *rightNode = pHead;

        rightNode = NextNode(rightNode, cycleLength);
        while(leftNode != rightNode) {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        return leftNode;
    }

};

// 断链法
// 两个指针, 一前一后, 两个指针同时向前移动, 每移动一次, 前面的指针的next指向NULL, 也就是访
// 问过的节点都断开, 最后到达的节点一定是尾节点的下一个, 也就是环中的第一个节点.
// 但这种方法修改了链表的指向
class Solution_Broken_Link {

public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) {
            return NULL;
        }

        ListNode* previous = pHead;
        ListNode* current = pHead->next;
        while(current != NULL) {
            previous->next = NULL;
            previous = current;
            current = current->next;
        }
        return previous;
    }

};


int __tmain( )
{
    Solution solu;

    ListNode list[6];

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 4;
    list[3].next = &list[4];

    list[4].val = 5;
    list[4].next = &list[5];

    list[5].val = 6;
    list[5].next = &list[2];

    cout <<solu.EntryNodeOfLoop(list)->val <<endl;
    cout <<"end";

    return 0;
}
