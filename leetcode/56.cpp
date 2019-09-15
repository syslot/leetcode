//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto flambda  = [](const vector<int> & a, const vector<int> & b){
            return a[0] < b[0];
        };

        sort(intervals.begin(),intervals.end(), flambda);
        return intervals;
    }
};

int main(){

    vector<vector<int> > intervals{{1,3},{8,10}, {2,6},{15, 18}};

    Solution s;
    auto rst = s.merge(intervals);
    for(auto v:rst){
        cout<< v[0] << " " <<v[1]<<endl;
    }

}