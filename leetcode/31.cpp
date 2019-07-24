//
// Created by syslot on 23/07/19.
//

#include "../common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        helpP(nums, 0);
        return;
    }

    void helpP(vector<int>& nums, int b){
        int size = nums.end() - nums.begin() - b;
        if(size == 1)
            return;
        if(size == 2) {
            swap(nums[b], nums[b+1]);
            return;
        }

        if(!CheckTailReverseOrder(nums, size-1)) {
            helpP(nums, b+1);
            return;
        }

        int pos = argminmax(nums, nums[b], b+1);
        if(pos == -1)
            sort(nums.begin() + b, nums.end());
        else{
            swap(nums[b], nums[pos]);
            sort(nums.begin()+b+1, nums.end());
        }

    }

    int argminmax(vector<int> & nums, int n, int begin){
        int pos = -1;
        for(int i = begin;i < nums.end() - nums.begin();i++){
            if(nums[i] > n){
                if(pos == -1 || nums[i] < nums[pos])
                    pos = i;
            }
        }
        return pos;
    }


    bool CheckTailReverseOrder(vector<int>& nums, int n){
        for(int i= nums.size()-1; i > nums.size() - n ;i--){
            if(nums[i-1] < nums[i])
                return false;
        }
        return true;
    }

};

int main() {

    vector<int> nums{1,2,3,4,5,6};
    Solution s;
    for(int i = 0;i<720;i++){
        s.nextPermutation(nums);
        for(auto i: nums)
            cout << i << " ";
        cout << endl;
    }
}
