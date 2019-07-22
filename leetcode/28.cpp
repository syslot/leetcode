//
// Created by syslot on 23/07/19.
//

#include "../common.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);



    }
};

int main(){

    string haystack = "aaaaaa";
    string needle = "bba";

    Solution s;
    cout << s.strStr(haystack, needle)<< endl;

}