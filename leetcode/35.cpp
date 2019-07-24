//
// Created by syslot on 24/07/19.
//

#include "../common.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int b = 0, e = nums.size();

        while(b < e){
            int m = (b+e)/2;
            if(target == nums[m])
                return m;
            else if(target > nums[m])
                b = m+1;
            else
                e = m;

        }
        return b;
    }
};


int main(){

    vector<int> nums{1,3,5,6};

    Solution s;
    cout<< s.searchInsert(nums, 2) << endl;

}