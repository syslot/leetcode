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
    int romanToInt(string s) {
        map<char, int> base = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        map<string, int> pre_base = {
                {"CM", 900},
                {"CD", 400},
                {"XC", 90},
                {"XL", 40},
                {"IX", 9},
                {"IV", 4}
        };
        int item = 0;
        int sum = 0;
        while (item != s.size()){
            string str = s.substr(item,2);
            if (auto it = pre_base.find(str); it != pre_base.end()){
                sum += it->second;
                item += 2;
            } else {
                auto it2 = base.find(s[item++]);
                sum += it2->second;
            }

        }
        return sum;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.romanToInt("III")<<endl;
    cout<<s.romanToInt("IV")<<endl;
    cout<<s.romanToInt("IX")<<endl;
    cout<<s.romanToInt("LVIII")<<endl;
    cout<<s.romanToInt("MCMXCIV")<<endl;
}