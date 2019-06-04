#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int sumNumbers(TreeNode* root) {

        if(root == NULL)
            return 0;
        
        auto sub = GetVal(root);

        if(sub.size() == 0) return root->val;

        auto sum = 0;
        for (string s : sub)
            sum += std::atoi(s.c_str());
        return sum;

    }

    vector<string> GetVal(TreeNode *root){

        vector<string> left, right;
        if(root->left != NULL){
            left = GetVal(root->left);
        }
        if(root->right != NULL){
            right = GetVal(root->right);
        }
        left.insert(left.end(), right.begin(), right.end());

        if(left.size()==0){
            return  {to_string(root->val)};
        }
        for_each(left.begin(), left.end(), [&root](string & v) -> void{ v = to_string(root->val) + v;});
        for(auto val:left){
            val+= 10*root->val;
        }
        return left;
    }
};

int main(){
    Solution s;

    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout << s.sumNumbers(root) << endl;
    
    
    root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);

    cout << s.sumNumbers(root) << endl;



}
