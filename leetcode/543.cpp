#include "../common.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        if(!root)
            return 0;
        
        if(!root->left)
            return getDep(root->right);
        if(!root->right)
            return getDep(root->left);

        int left = getDep(root->left);
        int right = getDep(root->right);
        return left+right;
        
    }

    int getDep(TreeNode * root){
        if(!root)
            return 0;

        return max(getDep(root->left), getDep(root->right)) + 1;

    }
};

int main(){
    
    auto root=new TreeNode(1);
    root->left =new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right= new TreeNode(6);
    root->right->right->left=new TreeNode(7);

    Solution s;
    cout << s.diameterOfBinaryTree(root) << endl;


}
