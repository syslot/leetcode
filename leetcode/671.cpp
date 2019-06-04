#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        if(t1 == NULL && t2 == NULL)
            return NULL;
        else if(t1 == NULL)
            return t2;
        else if(t2 == NULL)
            return t1;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        t1->val += t2->val;

        delete t2;
        return t1;
    }
};


int main(){
    Solution s = Solution();

    auto root = new TreeNode(3);
    root->left =  new TreeNode(5);
    root->right = NULL;
    auto r1 = new TreeNode(1);
    r1->left = root;
    r1->right = new TreeNode(2);

    auto t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->left->right = new TreeNode(4);
    t2->right = new TreeNode(3);
    t2->right->right = new TreeNode(7);


    auto t3 = s.mergeTrees(r1, t2);

    cout << t3 << endl;

}