//
// Created by syslot on 24/07/19.
//

#include "../common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(!binary_search(nums.begin(), nums.end(), target))
            return vector<int>{-1,-1};

        int l = search(nums, target-0.5);
        int r = search(nums, target+0.5);
        if(target != nums.back())
            r --;
        return vector<int>{l,r};
    }


    int search(vector<int> & nums, float target){

        int b = 0, e= nums.size()-1;

        while(b < e){
            int mid = (b+e)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
                e = mid;
            else
                b = mid+1;
        }
        return b;
    }

};


int main(){

    Solution s;
    vector<int> nums{5,7,7,8,8,10};
    int target = 10;

    auto rst = s.searchRange(nums, target);
    for(auto v:rst)
        cout << v << " ";
    cout << endl;

}