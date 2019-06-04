//
// Created by syslot on 2019-03-05.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        change(root, p->val, q->val);

        while(this->p != this->q){
            if(this->p > this->q)
                this->p/=2;
            else
                this->q/=2;
        }

        return new TreeNode(tree[this->p -1]);
    };

    void change(TreeNode *root, int p, int q){
        queue_.push(root);

        while (!queue_.empty()){
            auto head = queue_.front();
            queue_.pop();
            if(head == NULL){
                tree.push_back(INT_MAX);
                continue;
            }
            tree.push_back(head->val);
            if(head->left == NULL){
                queue_.push(NULL);
            }else queue_.push(head->left);
            if(head->right == NULL){
                queue_.push(NULL);
            }else queue_.push(head->right);
            if(p==head->val){
                this->p = tree.end() - tree.begin();
            }else if(q==head->val){
                this->q = tree.end() - tree.begin();
            }
        }

        return;
    }

    vector<int>tree;
    queue<TreeNode*> queue_;
    int p;
    int q;
};


int main(){
    Solution s = Solution();

//    auto root = new TreeNode(3);
//    root->left =  new TreeNode(5);
//    root->right = new TreeNode(1);
//    root->left->left = new TreeNode(6);
//    root->left->right = new TreeNode(2);
//    root->left->right->left = new TreeNode(7);
//    root->left->right->right = new TreeNode(4);
//    root->right->left = new TreeNode(0);
//    root->right->right= new TreeNode(8);
//[37,-34,-48,null,-100,-101,48,null,null,null,null,-54,null,-71,-22,null,null,null,8]
    auto root = new TreeNode(37);
    root->left = new TreeNode(-34);
    root->right = new TreeNode(-48);
    root->left->right = new TreeNode(-100);
    root->right->left = new TreeNode(-101);
    root->right->right = new TreeNode(48);
    root->right->right->left = new TreeNode(-54);
    root->right->right->left->left = new TreeNode(-71);
    root->right->right->left->right= new TreeNode(-22);
    root->right->right->left->right->right= new TreeNode(8);


    auto t3 = s.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(1));
    cout << t3->val << endl;

//    s.tree.clear();
//    t3 = s.lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));
//    cout << t3->val<<endl;

}