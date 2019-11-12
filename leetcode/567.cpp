#include "../common.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() == 0||s1.length() > s2.length()){
            return false;
        }

        int tgt[26];
        int src[26];

        memset(tgt, 0, sizeof(tgt));
        memset(src, 0, sizeof(src));
        
        for(int i=0;i<s1.length();i++){
            tgt[s1[i]-'a'] ++;
            src[s2[i]-'a'] ++;
        }

        if(memcmp(src,tgt, 104) == 0)
            return true;

        int ls1 = s1.length();
        for(int i=ls1;i<s2.length();i++){
            src[s2[i-ls1] -'a'] --;
            src[s2[i] - 'a'] ++;
            if(memcmp(src,tgt,sizeof(src)) ==0)
                return true;
        }

        return false;
    }
};

int main(){
    string s1="hello";
    string s2="ooolleoooleh";

    Solution s;
    cout << s.checkInclusion(s1, s2)<<endl;

}
