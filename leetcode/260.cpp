#include "../common.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int s=0;
        for(auto &v:nums){
            s ^= v;
        }

        int lowbit = s & -s;
        int a=0,b=0;
        for(auto &v:nums){
            if((lowbit & v) ==  lowbit){
                a^=v;
            }else{
                b^=v;
            }

        }
        vector<int> rst{a,b};
        
        return rst;
    }
};


int main(){
    vector<int> nums{1,2,1,3,2,5};

    Solution s;
    auto rst = s.singleNumber(nums);
    cout <<rst[0] << " " << rst[1] << endl;

}
