#include "../common.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minL = INT_MAX;
        int b=0,e=0;
        int ac = 0;
        while(e<nums.size()){
            ac+=nums[e];
            if(ac>=s){
                while(b<e){
                    if(ac-nums[b] >= s){
                        ac -= nums[b++];
                    }else
                        break;
                }
                minL = min(minL, e-b+1);
            }
            e++;
        }

        if(minL == INT_MAX)
            return 0;
        else 
            return minL;
    }
};

int main(){
    int s=15;
    vector<int> nums{1,2,3,4,5};

    Solution ss;
    cout << ss.minSubArrayLen(s, nums) <<endl;
}
