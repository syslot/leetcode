#include "../common.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> kv;
        for(auto &n:nums)
            kv[n]++;

        vector<pair<int, int>> hashv(kv.begin(), kv.end());
        sort(hashv.begin(), hashv.end(), [](pair<int,int>& a, pair<int, int> &b){ return a.second > b.second;});
        vector<int> rst;
        for(auto it = hashv.begin();it < hashv.begin() + k ; it++)
            rst.push_back(it->first);

        return rst;
    }
};

int main(){

    vector<int> nums{1,1,1,2,2,-1,-1,3};
    Solution s;
    int k=2;
    auto rst = s.topKFrequent(nums, k);
    for(auto v:rst)
        cout << v << " ";

    cout << endl;




}
