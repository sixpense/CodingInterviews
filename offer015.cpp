// 015-链表中倒数第k个节点


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL) {
            return NULL;
        }
        unsigned int i = 0;
        ListNode *right = pListHead;

        //left指针先走k-1步
        while(i < k - 1 && right != NULL) {
            debug <<"index = " <<i <<", value = " <<right->val <<endl;
            right = right->next;
            i++;
        }

        if(right == NULL) {
            cout <<"the list length = " <<i <<" < " <<k <<endl;
            return NULL;
        }

        ListNode *left = pListHead;
        while(right->next != NULL) {
            debug << "index = " <<i++ <<", value" <<right->val <<endl;

            left = left->next;
            right = right->next;
        }
        return left;
    }
};
