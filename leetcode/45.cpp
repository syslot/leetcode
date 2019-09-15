//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    int jump(vector<int>& nums) {

        int curFar = 0;
        int curEnd = 0;
        int steps  = 0;

        curFar = nums[0];
        for(int i =0; i<nums.size()-1; i++){
            curFar = max(curFar, nums[i] + i);

            if (i == curEnd){
                curEnd = curFar;
                steps ++;
            }
        }
        return steps;
    }
};

int main(){

    vector<int> nums{3,2,1,1,4};
//    for(int i =25000;i>=0;i--)
//        nums.push_back(i);
//
    Solution s;
    cout<< s.jump(nums) << endl;
//
}