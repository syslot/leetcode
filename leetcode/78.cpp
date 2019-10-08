#include "../common.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        uint64_t c;
        uint64_t bound = pow(2, nums.size()) -1;
        vector<vector<int>> rst;
        for(c=0;c<=bound;c++){
            vector<int> r;
            int j = c;
            for(int i=0;i<nums.size();i++){
                if(j & 0x1){
                    r.push_back(nums[i]);
                }
                j=j>>1;
            }
            rst.push_back(r);
        }
        return rst;
        
    }
};

int main(){

    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    Solution s;
    auto rst = s.subsets(nums);

    for(auto v:rst)
    {
        for(auto w:v)
            cout << w << " ";

        cout << endl;
    }


}
