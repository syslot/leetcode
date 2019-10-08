#include "../common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int mL[nums.size()];
        memset(mL, 0, sizeof(mL));

        int maxL = 1;
        for(int i=0;i<nums.size();i++){
            mL[i] =1;
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j] && mL[i] < mL[j]+1){
                    mL[i] = mL[j] +1;
                }
                if(mL[i]>maxL)
                    maxL = mL[i];
            }
        }
        return maxL;
    }
};

int main(){

    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution s;
    cout <<s.lengthOfLIS(nums) << endl;;
    

}
