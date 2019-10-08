#include "../common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode *> s_;

        while(root){
            s_.push(root);
            TreeNode * l =root->left;
            root->left =NULL;
            root = l;
        }

        while(!s_.empty()){
            auto r = s_.top();
            s_.pop();
            if(r->left){
                s_.push(r);
                TreeNode *l = r->left;
                r->left = NULL;
                r=l;
            }else{
                k --;
                if(k == 0){
                    return r->val;
                }
                if(r->right)
                    s_.push(r->right);
            }
        }

        return 0;


    }


};

int main(){

    Solution s;
    //auto root  = new TreeNode(5);
    //root->left = new TreeNode(3);
    //root->left->left = new TreeNode(2);
    //root->left->right = new TreeNode(4);
    //root->left->left->left = new TreeNode(1);
    //root->right=new TreeNode(6);
    
    auto root = BuildTree(vector<int>({41,37,44,24,39,42,48,1,35,38,40,INT_MAX,43,46,49,0,2,30,36,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,45,47,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,29,32,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,9,26,INT_MAX,31,34,INT_MAX,INT_MAX,7,11,25,27,INT_MAX,INT_MAX,33,INT_MAX,6,8,10,16,INT_MAX,INT_MAX,INT_MAX,28,INT_MAX,INT_MAX,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,15,19,INT_MAX,INT_MAX,INT_MAX,INT_MAX,12,INT_MAX,18,20,INT_MAX,13,17,INT_MAX,INT_MAX,22,INT_MAX,14,INT_MAX,INT_MAX,21,23}));


    int k = 6;

    cout << s.kthSmallest(root, k) <<endl;

}
