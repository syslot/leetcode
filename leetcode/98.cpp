#include "../common.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        int m,mm;
        return helpCheck(root, m, mm);
    }

    bool helpCheck(TreeNode *root, int & minV, int &maxV){
        
        bool flag;
        int minV_L, maxV_L, minV_R, maxV_R;
        if(root->left){
            flag = helpCheck(root->left, minV_L, maxV_L);
            if(flag == false || maxV_L >= root->val)
                return false;
        }
        if(root->right){
            flag = helpCheck(root->right, minV_R, maxV_R);
            if(flag == false || minV_R <= root->val)
                return false;
        }

        if(root->left == nullptr){
            minV = root->val;
        }else{
            minV = minV_L;
        }
        if(root->right == nullptr){
            maxV = root->val;
        }else{
            maxV = maxV_R;
        }
        return true;
    }
};

int main(){

    Codec c;

    auto root = c.deserialize("[2,1,3]");

    Solution s;
    cout << s.isValidBST(root) << endl;
}
