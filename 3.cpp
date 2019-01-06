//
// Created by syslot on 2018-12-28.
//

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto l = s.length();
        int maxLen = 0;
        map<char, string::iterator> hashMap = map<char, string::iterator> ();
        string::iterator it_l = s.begin();
        string::iterator it_r = s.begin();
        for(;it_r != s.end();){
            auto p = hashMap.find(*it_r);
            if (p == hashMap.end()) {
                hashMap.insert(pair<char, string::iterator>(*it_r, it_r));
            }else{
                // duplicated
                while (it_l <= p->second){
                    hashMap.erase(*(it_l++));
                }
                hashMap[*it_r] = it_r;
            }
            it_r ++;
            auto tmpLen = it_r - it_l;
            maxLen = tmpLen > maxLen? tmpLen : maxLen;
        }
        return maxLen;
    }
};

int main(){
    Solution s = Solution();

//    string str = "abcabcabc";
    string str = "pwwkew";

    cout << s.lengthOfLongestSubstring(str)<<endl;

}