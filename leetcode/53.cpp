//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int rst = res;

        for(int i=1;i<nums.size();i++){
            res = max(res+nums[i], nums[i]);
            rst = max(rst, res);
        }
        return rst;
    }
};

int main(){

    vector<int> nums{-1};//{-2,1,-3,4,-1,2,1,-5,4};


    Solution s;
    cout << s.maxSubArray(nums) << endl;

}