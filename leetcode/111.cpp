#include "../common.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return helper(root);
    }
    int helper(TreeNode *root){
        if(!root->left && !root->right)
            return 1;

        int left = INT_MAX, right = INT_MAX;
        if(root->left)
            left=helper(root->left);
        if(root->right)
            right = helper(root->right);
        
        return min(left, right) +1;
    }
};

int main(){
    string str = "[1,2,3,4]";

    auto root = BuildTree(str);
    Solution s;
    cout << s.minDepth(root) << endl;
}
