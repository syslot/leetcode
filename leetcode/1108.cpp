#include "../common.h"

class Solution {
public:
    string defangIPaddr(string address) {
        int idx = 0;
        string str;
        for(int i =0;i<address.length();i++){
            if(address[i] != '.')
                continue;
            str += address.substr(idx, i-idx);
            str += "[.]";
            idx = i+1;
            
        }
        str += address.substr(idx, address.length()-idx);
        return str;
    }
};

int main(){
    Solution s;
    cout << s.defangIPaddr("1.1.1.1")<<endl;

}
