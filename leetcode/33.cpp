//
// Created by syslot on 24/07/19.
//

#include "../common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0 || target > nums.back() && target < nums.front())
            return -1;
        if(nums.front() <= nums.back())
            return binarySearch(nums, target, 0, nums.size());
        int pos = searchBegin2(nums, 0, nums.size());
        if(target <= nums.back())
            return binarySearch(nums, target, pos, nums.size());
        else{
            return binarySearch(nums, target, 0, pos);
        }
    }

    int searchBegin(vector<int> & nums, int b, int e){
        if(e-b<=1)
            return b;
        if(e-b == 2)
            return nums[b]<nums[e-1]? b:e-1;

        int mid = (b+e)/2;
        if(mid == b or nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])
            return mid;
        if(nums[mid] > nums[mid+1])
            return mid+1;

        if(nums[mid] >= nums[b])
            return searchBegin(nums, mid+1, e);
        else
            return searchBegin(nums, b, mid);
    }

    int searchBegin2(vector<int> & nums, int b, int e){
        int left = 0;
        int right = nums.size() -1;

        while(left < right){
            int mid = (left+right)/2;
            if(nums[right] < nums[mid])
                left = mid+1;
            else
                right = mid;
        }
        return left;



    }

    int binarySearch(vector<int> & nums, int target, int b, int e){
        while(b < e){
            int m = (b+e)/2;
            if(target == nums[m])
                return m;
            else if (target > nums[m])
                b = m + 1;
            else
                e = m;
        }
        return -1;
    }
};



int main(){


    vector<int> nums = {3,1};//{4,5,6,7, 8, 8,-2, -1,0,1,2,3};

    Solution s;
    cout << s.search(nums, 1)<<endl;

//    cout << s.searchBegin(nums, 0, nums.size()) << endl;

}