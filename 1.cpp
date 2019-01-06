#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto it = nums.begin(); it != nums.end(); it++){
            for (auto it_p = it+1; it_p != nums.end(); it_p ++){
                if( *it + *it_p == target){
                    vector<int> ret;
                    ret.push_back(it - nums.begin());
                    ret.push_back(it_p - nums.begin());
                    return ret;
                }
            }
        }
        vector<int> ret;
        return ret;
    }
};

int main(){
    Solution s = Solution();
    int vec[] = {3,2,4};
    int target = 6;
    vector<int> nums(vec, vec+sizeof(vec)/sizeof(int));

    auto rsp = s.twoSum(nums, target);
    for(auto p:rsp) {

        cout<<p<<endl;
    }

}