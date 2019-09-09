//
// Created by syslot on 2019-08-22.
//


#include "../common.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        int length = floor(target / candidates[0]);
        vector


    }
};

int main(){

    Solution s;

    vector<int> cand {2,3,6,7};
    int target = 7;

    auto rst = s.combinationSum(cand,target);
    for(auto w: rst)
    {
        for(auto d:w)
            cout << d << " ";
        cout << endl;
    }

}
