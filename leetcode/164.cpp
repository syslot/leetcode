#include "../common.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int m = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] - nums[i-1] >m)
                m = nums[i] - nums[i-1];
        }

        return m;
        
    }
};

int main(){
    vector<int> nums{3,6,9,1};

    Solution s;
    cout << s.maximumGap(nums) <<endl;


}
