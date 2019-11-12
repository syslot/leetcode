#include "../common.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> st;
        int cm[26], cm1[26];

        memset(cm, 0 , sizeof(cm));
        memset(cm1, 0, sizeof(cm1));
        for(int i=0;i<s.length();i++)
            cm[s[i]-'a'] ++;
        for(int i=0;i<s.length();i++){
            bool enstack = true;
            if(st.size( ) == 0) {
                st.push_back(s[i]);
                cm1[s[i] - 'a'] ++;
            }
            else{
                if(cm1[s[i] - 'a'] == 0 && s[i] > st.back()){
                    st.push_back(s[i]);
                    cm1[s[i] - 'a'] ++;
                }else{
                    while(st.size() != 0){
                        if(s[i] == st.back() || cm1[s[i] - 'a'] > 0) {
                            cm[s[i] - 'a']--;
                            enstack = false;
                            break;
                        }else if(s[i] < st.back() && cm[st.back() - 'a'] > 1){
                            cm1[st.back()-'a'] -- ;
                            cm[st.back() - 'a'] --;
                            st.pop_back();
                        }else{
                            break;
                        }
                    }
                    if(enstack) {
                        cm1[s[i] - 'a']++;
                        st.push_back(s[i]);
                    }
                }
            }
        }
        string str(st.begin(), st.end());
        
        return str;
    }
};

int main(){
//    string str="cbacdcbc";
    string str  = "bbcaac";
    Solution s;
    cout << s.removeDuplicateLetters(str) << endl;
    return 0;
}
