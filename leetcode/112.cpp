#include "../common.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;

        return dfs(root,sum);
        
    }

    bool dfs(TreeNode *root, int sum){
        sum -= root->val;
        if(!root->left && !root->right){
            if(sum == 0)
                return true;
            else 
                return false;
        }

        bool flag=false;
        if(root->left)
            flag=dfs(root->left, sum);
        if(flag)
            return true;
        if(root->right)
            return dfs(root->right, sum);
        return false;
    }
};

int main(){

    auto root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
    Solution s;
    cout << s.hasPathSum(root, 22);

}
