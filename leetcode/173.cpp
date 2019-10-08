#include "../common.h"

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            stack_.push(root);
            root=root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int rst =-1;
        if(!stack_.empty()){
            auto root = stack_.top();
            stack_.pop();
            rst = root->val;
            if(root->right){
                root = root->right;
                while(root){
                    stack_.push(root);
                    root=root->left;
                }
            }
        }
        return rst;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack_.empty();
    }

    stack<TreeNode *> stack_;
};


int main(){
    auto root   = new TreeNode(7);
    root->left  = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right= new TreeNode(20);

    BSTIterator * it = new BSTIterator(root);

    cout << it->next() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;

    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;
    cout << it->next() << endl;
    cout << it->hasNext() << endl;


}
