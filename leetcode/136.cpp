#include "../common.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for(auto &i:nums){
            if(s.find(i) != s.end())
                s.erase(i);
            else
                s.insert(i);
        }
        return *s.begin();
   }
};


int main(){

    Solution s;
    vector<int> nums{2,2,1};
    cout << s.singleNumber(nums) << endl;

}
