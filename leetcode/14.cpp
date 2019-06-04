//
// Created by syslot on 2019-01-23.
//


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
//        string v_str = "\"\"";
//        auto v_str = [](string & s) -> string { return s.length()== 0 ? "\""+s+ "\"": string("\"\"");};
        if (strs.size()==0)
            return "";
        else if(strs.size()==1)
            return  strs[0];

        string basic = strs[0];
        for (auto i = 0; i<basic.length();i++){
            auto j = 1;
            while( j< strs.size()){
                 if (i>strs[j].length()){
                     return strs[j];
                 }
                 if (basic[i] != strs[j][i])
                    break;
                 j++;
            }
            if (j != strs.size()){
                return basic.substr(0,i);
            }
        }
        return basic;
    }
};

int main(){
    Solution s = Solution();
    vector<string> strs = {"flower","flow","flight"};
    cout<<s.longestCommonPrefix(strs)<<endl;
    strs = {"dog","racecar","car"};
    cout << s.longestCommonPrefix(strs)<<endl;
}