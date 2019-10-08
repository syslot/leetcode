//
// Created by syslot on 2019/9/19.
//

#include "../common.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        if(k==1)
            return true;
        if(nums.size() <k)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0)
            return false;

        sum/=k;
        int f[sum+1];
        memset(f, 0, sizeof(f));
        for(int i = 0;i<nums.size();i++){
            for(int v = sum; v >= nums[i]; v--){
                f[v] = max(f[v], f[v-nums[i]]+nums[i]);
            }
        }
        if(f[sum] == sum)
            return true;
        else
            return false;
    }
};


int main(){

    vector<int> nums{2,2,2,2,3,4,5};
    int k = 4;

    Solution s;
    cout << s.canPartitionKSubsets(nums, k) << endl;


}
