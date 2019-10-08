#include "../common.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        maxDeep = 0;
        dfs(root, 0);
        return maxDeep;
    }

    void dfs(TreeNode *root, int depth){
        if(root){
            depth ++;
            if(depth > maxDeep)
                maxDeep = depth;
            dfs(root->left, depth);
            dfs(root->right, depth);
        }
    }

    int maxDeep;
};

int main(){

    auto root = new TreeNode(3);
    root->left= new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.maxDepth(root) << endl;

}
