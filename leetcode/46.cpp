//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        visited.resize(nums.size());
        fill(visited.begin(),visited.end(), false);

        dfs(nums, 0);

        return p;
    }

    void dfs(vector<int> &nums, int i){
        if(i == nums.size()) {
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
};

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
    auto rst = s.permute(nums);
    for(auto w:rst) {
        for (auto i : w)
            cout << i << " ";
        cout << endl;
    }

}