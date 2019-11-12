#include "../common.h"


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0, threes=0;
        for(auto &v:nums){
            twos |= ones & v;
            ones ^= v;
            threes = ones&twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

int main(){

    vector<int> nums{1,1,1,2};
    Solution s;

    cout << s.singleNumber(nums) << endl;
}
