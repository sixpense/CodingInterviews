// 039-二叉树的深度
// 输入一个二叉树, 求该树的深度
// 从根结点到叶子结点依次经过的结点(含根, 叶子结点)形成树的一条路径, 最长路径的长度为树的深度.

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

// 调试开关
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
    // 二叉树深度
    int TreeDepth(TreeNode* root) {
        return TreeDepthRecursion(root, 0);
    }

    int TreeDepthRecursion(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        else {
            int leftDepth = TreeDepthRecursion(root->left);
            int rightDepth = TreeDepthRecursion(root->right);

            return max(leftDepth, rightDepth) + 1;

        }
    }

    // 递归方法二
    int TreeDepthRecursion(TreeNode *root, int depth) {
        if(root == NULL) {
            return depth;
        }
        else {
            int leftDepth = TreeDepthRecursion(root->left, depth + 1);
            int rightDepth = TreeDepthRecursion(root->right, depth + 1);

            return max(leftDepth, rightDepth);
        }
    }

    // 非递归方法
    int LevelOrderDev(TreeNode *root) {
        // deque双端队列
        // 支持迭代器, 有push_back()方法
        // 跟vector差不多, 比vector多了pop_front, push_front方法
        int count = 0;
        deque<TreeNode *> qFirst, qSecond;
        qFirst.push_back(root);

        while(qFirst.empty() != true) {
            while(qFirst.empty() != true) {
                TreeNode *temp = qFirst.front();
                qFirst.pop_front();

                cout <<temp->val;

                if(temp->left != NULL)
                {
                    qSecond.push_back(temp->left);
                }
                if(temp->right != NULL) {
                    qSecond.push_back(temp->right);
                }
            }
            cout << endl;
            count++;
            qFirst.swap(qSecond);
        }
        return count;
    }

    int LevelOrderUserPoint(TreeNode *root) {
        vector<TreeNode*> vec;
        vec.push_back(root);

        int cur = 0;
        int end = 1;
        int count = 0;

        while(cur < vec.size()) {
            end = vec.size();

            while(cur < end) {
                cout << vec[cur]->val;

                if(vec[cur]->left != NULL) {
                    vec.push_back(vec[cur]->left);
                }
                if(vec[cur]->right != NULL) {
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            cout <<endl;
            count++;
        }
        return count;
    }

    int LevelOrderUserSize(TreeNode *root) {
        int count = 0;

        int parentSize = 1, childSize = 0;
        TreeNode *temp = NULL;

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() != true) {
            temp = q.front();
            cout <<temp->val;

            q.pop();
            if(temp->left != NULL) {
                q.push(temp->left);
                childSize++;
            }
            parentSize--;
            if(parentSize == 0) {
                parentSize = childSize;
                childSize = 0;
                cout <<endl;
                count++;
            }
        }
        return count;
    }

    int LevelOrderUserEnd(TreeNode *root) {
        int count = 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while(q.empty() != true) {
            TreeNode* node = q.front();
            q.pop();

            if(node) {
                cout <<node->val;

                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            else if(q.empty() != true) {
                q.push(NULL);
                cout <<endl;
                count++;
            }
        }
        return count;
    }
};

int __tmain() {
//     0
//  1     2
//3
    TreeNode tree[4];
    tree[0].val = 0;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 1;
    tree[1].left = &tree[3];
    tree[1].right = NULL;

    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;

    tree[3].val = 3;
    tree[3].left = NULL;
    tree[3].right = NULL;

    Solution solu;

    cout <<solu.TreeDepth(tree) <<endl;

    cout <<solu.LevelOrderDev(tree) <<endl;

    cout <<solu.LevelOrderUserEnd(tree) <<endl;         // 报错

    cout <<solu.LevelOrderUserSize(tree) <<endl;

    cout <<solu.LevelOrderUserPoint(tree) <<endl;

    return 0;
}
