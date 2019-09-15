//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        queue<tuple<int, int>> q;

        bool visit[nums.size()];
        memset(visit, 0,sizeof(visit));

        visit[0] = true;
        q.push(make_tuple(0,nums[0]));

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int idx = get<0>(cur);
            int v   = get<1>(cur);

            for(int i = 1 ;i<= v ;i++){
                if(idx+i == nums.size()-1)
                    return true;
                if(idx+i >= nums.size())
                    break;

                if(!visit[idx+i]){
                    visit[idx+i] = true;
                    q.push(make_tuple(idx+i, nums[idx+i]));
                }
            }

        }
        return visit[nums.size()-1];
    }
};

int main(){
    vector<int> nums;
    Solution s;
    cout << s.canJump(nums)<< endl;
}