#include "../common.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;

        int mid = nums.size()/2;
        auto root = new TreeNode(nums[mid]);

        vector<int> lv(nums.begin(), nums.begin()+mid);
        vector<int> rv(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(lv);
        root->right = sortedArrayToBST(rv);
        
        return root;
    }
};

int main(){
    vector<int> nums{-10,-3,0,5,9};

    Solution s;
    auto root = s.sortedArrayToBST(nums);
    printT(root);

}
