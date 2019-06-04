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
    string intToRoman(int num) {
        int base[] = {1000, 500, 100, 50, 10, 5, 1};
        char *flags = "MDCLXVI";
        int pre_base[] = {900, 400, 90, 40, 9, 4};
        char pre_flags[6][3] = {"CM","CD", "XC", "XL", "IX", "IV"};

        int l = 7;
        int ls = 0;
        char str[32];
        for(auto i=0;i<l;i++){
            auto repeat = num / base[i];
            for(auto j=0; j< repeat; j++)
                str[ls++]=flags[i];
            num %= base[i];
            if(i<6){
                if (num >= pre_base[i] && num / pre_base[i] == 1){
                    num -= pre_base[i];
                    strcpy(str+ls, pre_flags[i]);
                    ls += 2;
                }
            }
        }
        str[ls] = 0;
        return str;
    }
};

int main(){
    Solution s = Solution();
    cout<<s.intToRoman(3)<<endl;
    cout<<s.intToRoman(4)<<endl;
    cout<<s.intToRoman(9)<<endl;
    cout<<s.intToRoman(58)<<endl;
    cout<<s.intToRoman(1994)<<endl;
}