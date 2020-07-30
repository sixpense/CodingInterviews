/*
 * 062-序列化二叉树
 * 请实现两个函数, 分别用来实现序列化和反序列化二叉树
 * 二叉树序列化是指: 把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串,
 * 使得内存中建立起来的二叉树可以持久保存.
 * 序列化二叉树可以基于先序, 中序, 后序和层序的二叉树遍历方式来进行修改, 序列化的结果十一个
 * 字符串, 序列化时通过某种符号表示空结点(#), 用!表示一个结点的结束(value!).
 * 
 * 二叉树的反序列化是指:根据某种遍历顺序得到序列化字符串结果str, 重构二叉树.
 */

// 选用vector<int> arr作为辅助, 最后转为int* 和char* 的数据类型, 由于'#'不方便表示, 因此用
// 一个不会出现的数0x23333代替.

#include <iostream>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdio>

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
    TreeNode(int x = 0): val(x), left(NULL), right(NULL) {

    }
};

class Solution {
public:
    vector<int> arr;
    void dfs(TreeNode* p) {
        if(!p) {
            arr.push_back(0x23333);         // 0x23333表示一个NULL, 最好用转椅字符'#'表示
        }
        else {
            arr.push_back(p->val);
            dfs(p->left);
            dfs(p->right);
        }
    }
    TreeNode* dfs2(int** str) {
        if(**str == 0x2333) {
            ++*str;
            return NULL;
        }
        else {
            TreeNode* res = new TreeNode(**str);
            ++*str;
            res->left = dfs2(str);
            res->right = dfs2(str);
            return res;
        }
    }
    char* Serialize(TreeNode *root) {
        arr.clear();
        dfs(root);
        int* res = new int[arr.size()];
        for(unsigned int i = 0; i < arr.size(); ++i) {
            res[i] = arr[i];
        }
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        TreeNode* res;
        int *p = (int*)str;
        res = dfs2(&p);
        return res;
    }
};

class Solution_char {
public:
    char* Serialize(TreeNode *root) {
        if(root == NULL) {
            char *serial = new char[3];
            strcpy(serial, "#,");
            return serial;
        }
        string str;
        Serialize(root, str);

        const char *c_str = str.c_str();
        char *serial = new char[str.length() + 1];
        strcpy(serial, c_str);

        return serial;
    }

    TreeNode* Deserialize(char *str) {
        if(str == NULL || *str == '\0') {
            return NULL;
        }
        int index = 0;
        return Deserialize(str, index);
    }
private:
    void Serialize(TreeNode *root, string &str) {
        if(root == NULL) {
            str += "#,";
            return ;
        }
        str += (toString(root->val) + ",");
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    // 反序列化二叉树
    // 将一个序列化的字符串转换成二叉树
    TreeNode* Deserialize(char *str, int &index) {
        if(str[index] == '#') {
            index += 2;
            return NULL;
        }
        // 获取结点的数学权值
        int num = 0;
        while(str[index] != ',' && str[index] != '\0') {
            num = num * 10 + (str[index] - '0');
            index++;
        }
        index++;

        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str, index);
        root->right = Deserialize(str, index);

        return root;
    }

    string toString(int num) {
        stringstream ss;
        ss <<num;
        return ss.str();
    }
};

int __tmain() {
    TreeNode tree[7];

    tree[0].val = 8;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];


    tree[1].val = 6;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];


    tree[2].val = 10;
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];


    tree[3].val = 5;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    tree[5].val = 9;
    tree[5].left = NULL;
    tree[5].right = NULL;

    tree[6].val = 11;
    tree[6].left = NULL;
    tree[6].right = NULL;

    Solution_char solu;
    cout <<solu.Serialize(tree) <<endl;
    cout <<solu.Serialize(solu.Deserialize(solu.Serialize(tree))) <<endl;

    return 0;
}
