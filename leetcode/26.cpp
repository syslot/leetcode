//
// Created by syslot on 23/07/19.
//


#include "../common.h"


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int sum = 1;
        int pre = 0;
        for(int i =1;i< nums.size();i++){
            if(nums[i] == nums[pre])
                continue;
            else{
                nums[++pre] = nums[i];
                sum++;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;

    vector<int> nums{1,1,2};

//    vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    int l = s.removeDuplicates(nums);

    for(int i =0;i<l;i++)
        cout << nums[i] << " ";

    cout << endl;



}