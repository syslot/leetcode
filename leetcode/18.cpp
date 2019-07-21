//
// Created by syslot on 21/07/19.
//

#include "../common.h"

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        if(nums.size() < 4)
//            return {};
//        sort(nums.begin(), nums.end());
//
//        vector<vector<int>> rst;
//        for(int t = 0;t< nums.size()-3;t++){
//            if(t > 0 && nums[t] == nums[t-1]) continue;
//            for(int k = t+1; k < nums.size()-2;k++) {
//                if (k > t + 1 && nums[k] == nums[k - 1])
//                    continue;
//                auto tmp_tgt = target - nums[t] - nums[k];
//
//                int i = k+1, j = nums.size() -1;
//
//                while(i<j){
//                    if(nums[i] + nums[j] == tmp_tgt){
//                        rst.push_back(vector<int>{nums[t], nums[k], nums[i], nums[j]});
//                        i++; j--;
//                        while(nums[i] == nums[i-1] && i < j) i++;
//                        while(nums[j]== nums[j+1] && i<j) j--;
//
//
//                    }else if (nums[i] + nums[j] < tmp_tgt)
//                        i++;
//                    else
//                        j--;
//                }
//            }
//        }
//
//        return rst;
//    }
//};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <= 3) return {};
        vector<vector<int>>v;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size()-2; j++) {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int k = j + 1, l = nums.size() - 1;
                while(k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target) {
                        v.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return v;
    }
};

int main(){
    Solution s;

//    vector<int> v{1, 0, -1, 0, -2, 2};

    vector<int> v{0,0,0,0};
    auto rst = s.fourSum(v, 0);

    for(auto v :rst) {
        for (auto i: v)
            cout << i << " ";
        cout << endl;
    }
}
