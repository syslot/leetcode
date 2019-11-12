#include "../common.h"


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;

        auto left = invertTree(root->right);
        auto right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }
};

int main(){

    auto root = new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left =new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);

    

}
