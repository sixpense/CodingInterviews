// 019-二叉树的镜像


class Solution {
public:
    void MirroPre(TreeNode *root) {
        if(root == NULL) {
            return ;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        while(node != NULL || nstack.empty() != true) {
            while(node != NULL) {
                if(node->left != NULL || node->right != NULL) {
                    swap(node->left, node->right);
                }

                nstack.push(node);
                node = node->left;
            }

            if(nstack.empty() != true) {
                node = nstack.top();
                nstack.pop();
                node = node->right;
            }
        }
    }

    void MirrorPreBFS(TreeNode *root) {
        if(root == NULL) {
            return ;
        }
        stack<TreeNode *> nstack;
        nstack.push(root);

        TreeNode *node = root;
        while(nstack.empty() != true) {
            node = nstack.top();
            nstack.pop();

            if(node->left != NULL || node->right != NULL) {
                swap(node->left, node->right);
            }

            if(node->left != NULL) {
                nstack.push(node->left);
            }

            if(node->right != NULL) {
                nstack.push(node->right);
            }
        }
    }
};
