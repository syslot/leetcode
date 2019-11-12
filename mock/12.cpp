#include "../common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int key = nums[0];
        for(int i=1;i<nums.size();i++){
            key ^= nums[i];
        }
        return key;
    }
};

int main(){
    vector<int> nums{4,1,2,1,2};
    Solution s;
    cout << s.singleNumber(nums) << endl;

}
