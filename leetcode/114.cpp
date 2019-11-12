#include "../common.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode *> s;

        if(root == nullptr)
            return;

        while(root){
            if(root->left && root->right == nullptr){
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }else if(root->left && root->right){
                s.push(root->right);
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }else if(root->left == nullptr && root->right){
                root= root->right;
            }else{
                if(!s.empty()){
                    root->right = s.top();
                    s.pop();
                }
                root= root->right;

            }
        }

        return ;
        
    }
};

int main(){

    Codec c;
    auto root = c.deserialize("[1,2,5,3,4,null,6]");

    Solution s;
    s.flatten(root);
    while(root){
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}
