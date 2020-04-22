// 006-重建二叉树

#include <iostream>
#include <vector>

using namespace std;

// 调试开关

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#ifdef __tmain

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}

    static void PreOrder(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        cout << root->val;
        PreOrder(root->left);
        PreOrder(root->right);
    }

    static void InOrder(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        InOrder(root->left);
        cout <<root->val;
        InOrder(root->right);
    }
};

#endif

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        //前序遍历的长度跟中序遍历的长度应该相同
        if(pre.size() != in.size()) {
            debug <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        int size = pre.size();
        if(size == 0) {
            debug <<"it's a NULL tree(length =0)" <<endl;
            return NULL;
        }

        int length = pre.size();
        debug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];
        TreeNode *root = new TreeNode(value);

        debug <<"the root is " <<root->val <<endl;

        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++) {
            if(in[rootIndex] == value) {
                debug <<"find the root at " <<rootIndex <<" in IN" <<endl;
                break;
            }
        }

        if(rootIndex >= length) {
            debug <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;

        debug << "left length = " << leftLength <<", right length = " <<rightLength <<endl;
        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength), inRight(rightLength);

        for(int i = 0; i < length; i++) {
            if(i < rootIndex) {
                // 前序遍历的第一个是根节点, 根后面的leftLength - 1是左子树,因此是i+1;
                preLeft[i] = pre[i + 1];
                inLeft[i] = in[i];
                debug <<preLeft[i] <<inLeft[i] <<" ";
            }
            else if(i > rootIndex) {
                preRight[i - rootIndex - 1] = pre[i];
                inRight[i - rootIndex -1] = in[i];
                debug<< preRight[i - rootIndex - 1] <<inRight[i - rootIndex - 1] <<" ";
            }
        }
        debug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++) {
            debug <<preLeft[i] <<inLeft[i] <<" ";
        }
        debug <<endl;
        debug <<"the right tree" <<endl;

        for(int i = 0; i < rightLength; i++) {
            debug <<preRight[i] <<inRight[i] <<" ";
        }
        debug <<endl;

        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }
};

int __tmain() {
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};

    vector<int> preOrder(pre, pre + 8);
    vector<int> inOrder(in, in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout <<"PreOrder";
    TreeNode::InOrder(root);
    cout <<endl;

    return 0;
}

