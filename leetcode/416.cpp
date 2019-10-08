//
// Created by syslot on 2019/9/19.
//

#include "../common.h"


class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum %2 != 0 || nums.size() == 1)
            return false;

        sum /= 2;
        int p[sum+1];
        memset(p, 0, sizeof(p));
        for(int i = 2;i<=sum;i++){
            p[i] = -1000000;//-numeric_limits<int>::infinity();
        }


        for(int i =0; i<nums.size();i++){
            for(int v = sum;v>=nums[i];v--){
                p[v] = max(p[v], p[v-nums[i]] + nums[i]);
            }
//            for(int i = 0;i<=sum;i++)
//                cout<<p[i] << " ";
//            cout << endl;
        }
        if(p[sum] == sum)
            return true;
        else
            return false;

    }
};


int main(){

    vector<int> nums{1, 5, 11, 5};

    Solution s ;
    cout << s.canPartition(nums) << endl;



}