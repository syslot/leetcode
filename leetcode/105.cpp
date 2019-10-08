#include "../common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        auto root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), root->val);
        
        vector<int> inL(inorder.begin(), it);
        vector<int> inR(it+1, inorder.end());

        vector<int> preL(preorder.begin()+1, preorder.begin()+1+inL.size());
        vector<int> preR(preorder.end()-inR.size(), preorder.end());

        root->left = buildTree(preL, inL);
        root->right = buildTree(preR, inR);
        return root;
    }
};


void printT(TreeNode *root){
    if(root){
        cout << root->val << endl;
        printT(root->left);
        printT(root->right);
    }
}

int main(){
    Solution s;

    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    auto root=s.buildTree(preorder, inorder);


    printT(root);

}
