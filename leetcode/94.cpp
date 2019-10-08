#include "../common.h"

struct node{
    TreeNode * ptr;
    int s;
    node(TreeNode *ptr, int s){this->ptr =ptr; this->s = s;}
};

class Solution {


public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Recursive version
        if(root)
            StackTravel(root);
        return rst;
    }

    void RecursiveTravel(TreeNode * root){
        if(root){
            RecursiveTravel(root->left);
            rst.push_back(root->val);
            RecursiveTravel(root->right);
        }
    }


    void StackTravel(TreeNode *root){
        stack<node> stack_;
        stack_.push(node(root, 0));
        while(!stack_.empty()){
            auto p = stack_.top();
            stack_.pop();
            if(p.s == 0){
                p.s = 1;
                stack_.push(p);
                if(p.ptr->left)
                    stack_.push(node(p.ptr->left, 0));
            }else{
                rst.push_back(p.ptr->val);
                if(p.ptr->right){
                    p.ptr = p.ptr->right;
                    p.s = 0;
                    stack_.push(p);
                }

            }
        }

    }
    vector<int> rst;
};

int main(){
    
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    auto r = s.inorderTraversal(root);
    for(auto w:r){
        cout << w << " ";
    }
    cout << endl;


}
