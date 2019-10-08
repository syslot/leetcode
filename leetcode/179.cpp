//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto flambda  = [](const int & a, const int & b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        };

        sort(nums.begin(),nums.end(), flambda);
        string s;
        for(auto i: nums)
            s+=to_string(i);
        unsigned i =0;
        while(i < s.length())
            if(s[i] == '0' && i != s.length()-1) {
                i++;
                continue;
            }
            else
                break;

        if(i<=s.length()-1)
            return s.c_str() + i;
    }
};

int main(){
    Solution s;
//    auto q = vector<int>{30,3,34,3,5,9};
    auto q = vector<int>{1440,7548,4240,6616,733,4712,883,8,9576};
    cout << s.largestNumber(q) << endl;

}