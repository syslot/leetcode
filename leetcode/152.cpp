#include "../common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxP[nums.size()];
        int minP[nums.size()];

        maxP[0] = minP[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] >= 0){
                maxP[i] = max(maxP[i-1] * nums[i], nums[i]);
                minP[i] = min(minP[i-1] * nums[i], nums[i]);
            }else{
                maxP[i] = max(minP[i-1]*nums[i], nums[i]);
                minP[i] = min(maxP[i-1]*nums[i], nums[i]);
            }
        }
        int largest = maxP[0];
        for(int i=1;i<nums.size();i++)
            if(largest < maxP[i])
                largest = maxP[i];
        return largest;
    }
};

int main(){
    vector<int> nums{2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums)<<endl;

}
