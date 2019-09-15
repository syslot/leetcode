//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        visited.resize(nums.size());
        fill(visited.begin(),visited.end(), false);

        dfs(nums, 0);

        return p;
    }

    void dfs(vector<int> &nums, int i){
        if(i == nums.size()) {
            string s;
            s.reserve(nums.size());
            for(auto t:arr){
                s += '0'+ t;
            }
            if(filter.find(s) != filter.end())
                return;

            filter.insert(s);
            p.push_back(arr);
            return;
        }

        for(int j=0; j<nums.size();j++){
            if(!visited[j]){
                visited[j] = true;
                arr.push_back(nums[j]);
                dfs(nums, i+1);
                arr.pop_back();
                visited[j] = false;
            }
        }
    }

    vector<bool> visited;
    vector<vector<int> > p;
    vector<int> arr;
    set<string> filter;
};

int main(){

    vector<int> nums{1,1,3};

    Solution s;
    auto rst = s.permuteUnique(nums);
    for(auto w:rst) {
        for (auto i : w)
            cout << i << " ";
        cout << endl;
    }

}