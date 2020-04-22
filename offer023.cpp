// 023-从上到下打印二叉树
//

#include <iostream>
#include <vector>
#include <deque>
#include <queue>


using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif

#define undebug 0&& cout

#ifdef __tmain

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif

class Solution {
private:
    vector<int> res;

public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        // 方法1
        LevelOrder(root);

        // 方法2
        LevelOrderDev(root);

        // 方法3
        LevelOrderUseSize(root);

        // 方法4
        LevelOrderUseEnd(root);

        return this->res;
    }

    int PrintLevel(TreeNode *root, int level) {
        if(root == NULL || level < 0) {
            return 0;
        }
        else if(level == 0) {
            debug <<root->val;
            res.push_back(root->val);

            return 1;
        }
        else {
            return PrintLevel(root->left, level - 1) + PrintLevel(root->right, level - 1);
        }
    }

    void LevelOrder(TreeNode *root) {
        res.clear();
        if(root == NULL) {
            return ;
        }
        for(int level = 0; ; level++) {
            if(PrintLevel(root, level) == 0) {
                break;
            }
            debug <<endl;
        }
    }

    //////////////////////////////
    //    使用两个双端队列
    //////////////////////////////

    void LevelOrderDev(TreeNode *root) {
        res.clear();

        deque<TreeNode *> qFirst, qSecond;          //和vector差不多, 多了pop_front, push_front方法
        qFirst.push_back(root);

        while(qFirst.empty() != true) {
            while(qFirst.empty() != true) {
                TreeNode *temp = qFirst.front();
                qFirst.pop_front();

                debug << temp->val;
                res.push_back(temp->val);

                if(temp->left != NULL) {
                    qSecond.push_back(temp->left);
                }
                if(temp->right != NULL) {
                    qSecond.push_back(temp->right);
                }
            }
            debug <<endl;
            qFirst.swap(qSecond);
        }
    }

    //////////////////////////////////
    //  使用双指针标识当前指针和结束
    //////////////////////////////////

    void LevelOrderUserPoint(TreeNode *root) {
        res.clear();
        vector<TreeNode*> vec;
        vec.push_back(root);

        int cur = 0;
        int end = 1;

        while(cur < vec.size()) {
            end = vec.size();

            while(cur < end) {
                debug << vec[cur]->val;
                res.push_back(vec[cur]->val);

                if(vec[cur]->left != NULL) {
                    vec.push_back(vec[cur]->left);
                }
                if(vec[cur]->right != NULL) {
                    vec.push_back(vec[cur]->right);
                }
                cur++;
            }
            debug << endl;
        }
    }


    //////////////////////////////////
    //  使用parent和childSize标识前一层和当前层的节点个数
    //////////////////////////////////
    void LevelOrderUseSize(TreeNode *root) {
        res.clear();

        int parentSize = 1, childSize = 0;
        TreeNode *temp = NULL;

        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() != true) {
            temp = q.front();
            debug <<temp->val;
            res.push_back(temp->val);

            q.pop();

            if(temp->left != NULL) {
                q.push(temp->left);
                childSize++;
            }
            if(temp->right != NULL) {
                q.push(temp->right);
                childSize++;
            }

            parentSize--;
            if(parentSize == 0) {
                parentSize = childSize;
                childSize = 0;
                debug << endl;
            }
        }
    }

    ////////////////////////////////////
    //  在队列中插入结束标识来标识当前层结束
    ////////////////////////////////////
    void LevelOrderUseEnd(TreeNode *root) {
        res.clear();

        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL);

        while(q.empty() != true) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node) {
                debug << node->val;
                res.push_back(node->val);

                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            else if(q.empty() != true) {
                q.push(NULL);
                debug << endl;
            }
        }
    }

    struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        if(pre.size() != in.size()) {
            undebug <<"the length of PRE and IN should be same" <<endl;
            return NULL;
        }

        int size = pre.size();
        if(size == 0) {
            undebug <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }
        int length = pre.size();
        undebug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];
        TreeNode *root = new TreeNode(value);

        undebug <<"the root is" <<root->val <<endl;

        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++) {
            if(in[rootIndex] == value) {
                undebug <<"find the root at " <<rootIndex <<"in IN." <<endl;
                break;
            }
        }
        if(rootIndex >= length) {
            undebug <<"can't find root (value = "<<value <<") in IN." <<endl;
            return NULL;
        }

        // 区分左子树和右子树
        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;
        undebug <<"left length = " <<leftLength <<", rightLength = " <<rightLength <<endl;
        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength), inRight(rightLength);

        for(int i = 0; i < length; i++) {
            if(i < rootIndex) {
                // 前序遍历的第一个是根节点,根后面的(leftLength = rootIndex) - 1 个节点是左
                // 子树, 后面是右子树.
                preLeft[i] = pre[i + 1];
                // 中序遍历前(leftLength = rootIndex) - 1个节点是左子树, 第rootIndex个节点
                // 是根,然后是右子树.
                inLeft[i] = in[i];
                undebug <<preLeft[i] <<inLeft[i] <<" ";

            }
            else if(i > rootIndex) {
                preRight[i - rootIndex -1] = pre[i];
                inRight[i - rootIndex -1] = in[i];
                undebug <<preRight[i - rootIndex -1] <<inRight[i - rootIndex - 1] <<" ";
            }
        }
        undebug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++) {
            undebug <<preLeft[i] <<inLeft[i] <<" ";
        }
        undebug <<endl;
        undebug <<"the right tree" <<endl;
        for(int i = 0; i < rightLength; i++) {
            undebug <<preRight[i] <<inRight[i] <<" ";
        }
        undebug <<endl;

        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }
};

int __tmain() {
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};

    vector<int> preOrder(pre, pre+8);
    vector<int> inOrder(in, in+8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);
    solu.PrintFromTopToBottom(root);

    return 0;
}
