//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, one=0, two=0;
        for(auto i:nums)
            switch(i){
            case 0:
                zero++;
                break;
            case 1:
                one++;
                break;
            case 2:
                two++;
        }
        fill(nums.begin(), nums.begin()+zero,0);
        fill(nums.begin()+zero, nums.begin()+one+zero, 1);
        fill(nums.end()-two, nums.end(), 2);
    }
};

int main(){

    vector<int> nums{2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);
    for(auto w:nums){
        cout << w << " ";
    }
    cout << endl;


}