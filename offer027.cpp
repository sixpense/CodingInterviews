// 027-二叉搜索树与双向链表
// 输入一个二叉搜索树,将该二叉搜索树转换成一个排序的二叉链表.
// 要求不能创建任何新的结点,只能调整树众结点指针的指向.
//
// 分析:
// 二叉排序树的每个节点均由两个指针指向其两个孩子,双向链表中每个节点又都有两个指针指向其前
// 驱和后继
// 二叉排序树的左节点的值<根节点的值<右节点的值
// 中序遍历实现二叉搜索树向双向链表的转换,访问过程需修改为链接操作
// 把左子树和右子树都转换成排序的双向链表之后再和根节点链接起来,整颗二叉搜索树就转换成了排
// 序的双向链表
//

#include <iostream>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

#ifdef __tmain
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

#endif

class Solution {
public:
    /*
     * [Convert description]
     * @Author
     * @DateTime 2020-04-21
     * @param               [二叉排序树的根]
     * @return              [转换成的链表的头结点]
     */
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == NULL) {
            return 0;
        }
        TreeNode *pLastNode = NULL;
        ConvertRecursion(pRootOfTree, &pLastNode);

        // 当递归结束后,*pLastNode指向了双向链表的尾节点
        TreeNode *node = pLastNode;
        while(pLastNode != NULL && pLastNode->left != NULL) {
            pLastNode = pLastNode->left;
        }
        return pLastNode;
    }

    /**
     * [ConvertRecursion] 递归的将root为根的二叉排序树专户才能成双向链表
     * @param root          [当前递归的二叉树的根节点]
     * @param pLastNode     [中序遍历中指向前一个节点的指针]
     */
    void ConvertRecursion(TreeNode *root, TreeNode **pLastNode) {
        if(root == NULL)
            return ;

        TreeNode *currNode = root;
        // 首先中序,递归左子树
        if(currNode->left != NULL) {
            ConvertRecursion(root->left, pLastNode);
        }

        // 中序遍历根节点
        currNode->left = *pLastNode;
        if(*pLastNode != NULL) {
            (*pLastNode)->right = currNode;
        }
        else {
            debug <<"lastNode is NULL" <<endl;
        }

        debug <<((*pLastNode == NULL) ? -1 : (*pLastNode)->val) <<", " <<currNode->val <<endl;
        system("PAUSE");

        // 更新上一个访问的指针域
        *pLastNode = currNode;

        if(currNode->right != NULL) {
            ConvertRecursion(currNode->right, pLastNode);
        }
    }
};



// 非递归中序遍历实现
//
class Solution_1 {
public:
    TreeNode* Convert(TreeNode* root) {
        if(root == NULL) {
            debug <<"The tree is NULL..." <<endl;
        }

        stack<TreeNode *> nstack;
        TreeNode *currNode = root;
        TreeNode *preNode = NULL;
        TreeNode *head = NULL;

        while(currNode != NULL || nstack.empty() != true) {
            while(currNode != NULL) {
                nstack.push(currNode);
                currNode = currNode->left;
            }
            if(nstack.empty() != true) {
                currNode = nstack.top();
                debug <<currNode->val;
                nstack.pop();

                //第一个节点
                if(preNode == NULL) {
                    head = currNode;
                    preNode = currNode;
                }
                else {
                    preNode->right = currNode;
                    currNode->left = preNode;
                    preNode = currNode;
                }
                currNode = currNode->right;
            }
        }
        return head;
    }
};


// 递归将左右子树变换为链表后,将他们与根链接成链表

class Solution_2 {
    /*
     * [Convert description]
     * @param pRootOfTree                   [二叉排序树的根]
     * @return                              [转换成的链表的头节点]
     */
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == NULL) {
            return NULL;
        }
        TreeNode *pLastNode = ConvertRecursion(pRootOfTree);

        TreeNode *node = pLastNode;
        while(pLastNode != NULL && pLastNode->left != NULL) {
            pLastNode = pLastNode->left;
        }
        return pLastNode;
    }

    /**
     * [ConvertRecursion] 递归的将root为根的二叉排序树转换成双向链表
     * @param root              [当前递归的二叉排序树的根节点]
     */
    TreeNode* ConvertRecursion(TreeNode *root) {
        if(root == NULL) {
            debug << "NULL" <<endl;
            return NULL;
        }

        TreeNode* pLastNode = NULL;
        if(root->left != NULL) {
            lastNode = ConvertRecursion(root->left);

            while(lastNode != NULL && lastNode->right != NULL) {
                lastNode = lastNode->right;
            }
            root->left = lastNode;
            lastNode->right = root;
            debug <<lastNode->val << ", " <<root->val <<endl;
        }

        TreeNode* nextNode = NULL;
        if(root->right != NULL) {
            nextNode = ConvertRecursion(root->right);

            while(nextNode->left != NULL) {
                nextNode = nextNode->left;
            }
            nextNode->left = root;
            root->ritht = nextNode;
            debug <<root->val <<", " <<nextNode->val <<endl;
        }
        return root;
    }
}

int __tmain() {
    //    9
    //  5   18
    //2  7    99
    TreeNode tree[6];
    tree[0].val = 9;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 5;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[2].val = 18;
    tree[2].left = NULL;
    tree[2].right = &tree[5];
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;
    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[5].val = 99;
    tree[5].left = NULL;
    tree[5].right = NULL;

    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL) {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}

