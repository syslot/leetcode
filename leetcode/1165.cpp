#include "../common.h"

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int kidx[26];
        for(int i =0;i<26;i++)
            kidx[keyboard[i]-'a'] = i;
        
        char c = keyboard[0];
        int sum = 0;
        for(auto ch:word){
            sum += abs(kidx[ch-'a']-kidx[c-'a']);
            c = ch;
        }
        return sum;
    }
};

int main(){
    Solution s;

    string keyboard = "pqrstuvwxyzabcdefghijklmno";//"abcdefghijklmnopqrstuvwxyz";

    string word = "leetcode";//"cba";
    cout << s.calculateTime(keyboard, word)<<endl;

}
