/*
 * 063-二叉搜索树的第K个结点
 * 给定一个二叉搜索树, 请找出其中的第K小的结点.
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x = 0) :
            val(x), left(NULL), right(NULL) {
    }
};


// 二叉搜索树中序遍历是一个递增序列, 因此中序遍历的第K个结点就是二叉搜索树的第K个结点
class Solution {
    unsigned int count = 0;
public:
    TreeNode* KthNode(TreeNode* root, unsigned int K) {
        TreeNode *ret = NULL;
        if(root == NULL) {
            return ret;
        }

        if((ret = KthNode(root->left, K)) != NULL) {
            return ret;
        }
        ++count;
        debug <<"count = " <<count <<", value = " <<root->val <<endl;
        if(count == K) {
            return ret;
        }
        if((ret = KthNode(root->right, K)) != NULL) {
            return ret;
        }
        return NULL;
    }
};

class Solution_2 {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot == NULL || k < 0) {
            return NULL;
        }
        vector<TreeNode*> vec;
        InOrder(pRoot, vec);
        if(k>vec.size()) {
            return NULL;
        }
        return vec[k - 1];
    }

    void InOrder(TreeNode* pRoot, vector<TreeNode*>& vec) {
        if(pRoot == NULL)
            return ;
        InOrder(pRoot->left, vec);
        vec.push_back(pRoot);
        InOrder(pRoot->right, vec);
    }
}

int __tmain() {
    TreeNode tree[7];

    tree[0].val = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 7;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 4;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 6;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 8;
    tree[6].left = NULL;
    tree[6].right = NULL;

    Solution solu;
    TreeNode *res = NULL;
    if((res = solu.KthNode(tree, 3)) != NULL) {
        cout <<res->val <<endl;
    }
    else {
        cout <<"null node" <<endl;
    }
    return 0;
}

