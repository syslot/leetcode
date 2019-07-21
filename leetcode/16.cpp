#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int rst = INT32_MAX;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int bias = nums[k] + nums[i] + nums[j] - target;
                if(bias == 0)
                    return target;

                if(abs(bias) < abs(rst))
                    rst = bias;
                if (bias < 0)
                    i++;
                else
                    j--;

            }
        }
        return rst+target;
    }
};


int main(){
    Solution s;

    vector<int> v{-1, 2, 1,4};

    auto rst = s.threeSumClosest(v, 1);

    cout<<rst<<endl;

}
