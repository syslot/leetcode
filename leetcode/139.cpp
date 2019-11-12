#include "../common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto & prefix : wordDict){
            int len = prefix.length();
            
            int pos1 =0, pos2=0;
            while(pos1 < s.length() && pos2 < prefix.length()){
                if(s[pos1] == prefix[pos2]){
                    pos1++;
                    pos2++;
                }else
                    break;
            }
            if(pos1 == s.length() && pos2 == s.length() && s[pos1] == prefix[pos2])
                return true;
            else{
                if(pos1==s.length() && pos2 != prefix.length() || pos1 != s.length() && pos2 != prefix.length()){
                    continue;
                }else{
                    bool flag = wordBreak(s.substr(pos2, s.length()-pos2), wordDict);
                    if(flag) 
                        return true;
                }
            }
        }
        return false;
        
    }
};

int main(){
    Solution s;
    string str  = "catsandog";
    vector<string> wd = {
        "cats",
        "dog",
        "sand",
        "and",
        "cat"
    };

    cout << s.wordBreak(str, wd)<< endl;


}
