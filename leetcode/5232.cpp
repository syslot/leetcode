#include "../common.h"


class Solution {
public:
    int balancedString(string s) {

        map<char, int> m;
        for(auto &ch:s)
            m[ch] ++;

        int ave = s.length()/4;
        
        
    }
};

int main(){

    string str="QWER";
    Solution s;
    cout << s.balancedString(str) << endl;
}
