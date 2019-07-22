//
// Created by syslot on 23/07/19.
//

#include "../common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if(nums.size()==0) return 0;
        int sum = 0;
        int cur = 0;
        for(int i =0;i< nums.size();i++){
            if(nums[i] == val)
                continue;
            else{
                nums[cur++] = nums[i];
                sum++;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;

    vector<int> l{0,1,2,2,3,0,4,2};
//    vector<int> l{3,2,2,3};
    int len = s.removeElement(l, 2);

    for(int i=0;i<len;i++){
        cout << l[i] << " ";
    }

    cout << endl;
}