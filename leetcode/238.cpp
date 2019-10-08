#include "../common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int res[nums.size()];
        int k = res[0] =1;
        for(int i =1;i<nums.size();i++){
            k*=nums[i-1];
            res[i] = k;
        }
        k=1;
        for(int i =nums.size()-1;i>=0;i--){
            res[i] *=k ;
            k *= nums[i];
        }
        return vector<int>(res, res+nums.size());
        
    }
};

int main(){
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    Solution s;
    auto rst = s.productExceptSelf(nums);
    for(auto &x:rst)
        cout << x << " ";
    cout << endl;

}
