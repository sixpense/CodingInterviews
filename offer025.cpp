// 025-二叉树中和为某一值的路径
// 输入一个二叉树和一个整数, 打印出二叉树中节点值的和为输入整数的所有路径.
// 路径定义为从树的根节点往下一直到叶节点所经过的结点形成一条路径.
//

#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

#define undebug 0 && cout 

#ifdef __tmain
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    // TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif

class Solution {
public:
    vector< vector<int> > m_res;

    vector< vector<int> > FindPath(TreeNode* root, int expectNumber) {
        if(root == NULL) {
            return m_res;
        }
        vector<int> path;
        FindPath(root, expectNumber, path, 0);

        return m_res;
    }

    void FindPath(TreeNode* root, int expectNumber, vector<int> path, int currentSum) {
        currentSum += root->val;
        path.push_back(root->val);

        if(currentSum == expectNumber && ((root->left == NULL && root->right == NULL))) {
            debug <<"find a path" <<endl;
            for(int i = 0; i < path.size(); i++) {
                debug <<path[i] <<" ";
            }
            debug <<endl;

            m_res.push_back(path);
        }

        if(root->left != NULL) {
            FindPath(root->left, expectNumber, path, currentSum);
        }
        if(root->right != NULL) {
            FindPath(root->right, expectNumber, path, currentSum);
        }

        // 此处不需要恢复currentSum和path的值
        // currentSum作为参数在函数递归调用返回时会自动恢复
        // 如果作为静态局部变量则需要进行恢复
        // currentSum -= root->val;
        // path.pop_back()
    }
};

int __tmain() {
    TreeNode tree[5];
    tree[0].val = 10;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 5;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 12;
    tree[2].left = NULL;
    tree[2].right = NULL;

    tree[3].val = 4;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    Solution solu;
    vector< vector<int> > res = solu.FindPath(&tree[0], 19);
    cout << "size = " <<res.size() <<endl;
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}
