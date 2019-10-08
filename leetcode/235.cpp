#include "../common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int min_ = min(p->val, q->val);
        int max_ = max(p->val, q->val);
        if(min_ == root->val || max_ == root->val || min_ < root->val && max_ > root-> val)
            return root;
        if(min_ < root->val && max_ < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else 
            return lowestCommonAncestor(root->right, p, q);
            

        
    }
};

int main(){
    
    auto root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right= new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution s;

    auto p = new TreeNode(2);
    auto q = new TreeNode(4);
    cout << s.lowestCommonAncestor(root,p,q)->val << endl;
    

}
