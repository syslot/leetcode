#include "../common.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;

        int l = depth(root->left);
        int r = depth(root->right);
        
        if(l == -1 || r == -1 || abs(l-r)>1)
            return false;
        else
            return true;

    }

    int depth(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int d_l = depth(root->left);
        int d_r = depth(root->right);
        if(d_l == -1 || d_r == -1 || abs(d_l-d_r)>1)
            return -1;
        else
            return max(d_l, d_r) + 1;

    }
};

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right= new TreeNode(4);

    Solution s;
    cout << s.isBalanced(root) << endl;


}
