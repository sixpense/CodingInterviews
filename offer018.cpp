// 018-树的子结构



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

    TreeNode(int x): val(x), left(NULL), right(NULL) {  }

};

#endif

class Solution {
public:
    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child) {
        if(child == NULL) {
            return true;
        }
        else if(parent == NULL) {
            return false;
        }

        if(parent->val != child->val) {
            return false;
        }
        else {
            return DoesParentHaveChild(parent->left, child->left) 
                && DoesParentHaveChild(parent->right, child->right);
        }
    }

    bool HasSubtree(TreeNode* parent, TreeNode* child) {
        if(child == NULL) {
            return false;
        }
        else if(parent == NULL) {
            return false;
        }

        bool result;

        // 如果当前父树的节点与子树相同, 则直接从父树的当前位置开始判定
        if(parent->val == child->val) {
            result = DoesParentHaveChild(parent, child);
        }

        if(result != true) {
            return HasSubtree(parent->left, child)
                || HasSubtree(parent->right, child);
        }
        else {
            return true;
        }
    }
};

int __tmain() {
    debug <<"test" <<endl;
    return 0;
}
