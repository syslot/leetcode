#include "../common.h"
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        s.push(root);
        vector<int> rst;
        while(!s.empty()){
            auto cur = s.top();
            if(cur->right != nullptr){
                s.push(cur->right);
                cur->right = nullptr;
            }
            if(cur->left != nullptr){
                s.push(cur->left);
                cur->left = nullptr;
            }
            if(s.top() != cur)
                continue;
            else{
                rst.push_back(cur->val);
                s.pop()
            }
        }
        return rst;
    }
};
int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);


    Solution s;
    auto p = s.postorderTraversal(root);
    for(auto & x:p)
        cout << x << " ";
    cout << endl;
}
