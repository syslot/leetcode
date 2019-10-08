#include "../common.h"

class Solution {
public:
    string decodeString(string s) {
        if(s.length()==0)
            return "";

        stack<int> rs;
        stack<string> str;

        string snap;
        int rep=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')
                rep = rep*10 + s[i] - '0';
            else if(s[i] >='a' && s[i]<='z' || s[i] >='A'&&s[i] <='Z')
                snap += s[i];
            else if(s[i]=='['){
                rs.push(rep);
                rep = 0;
                str.push(snap);
                snap = "";
            }else{
                int r = rs.top();
                rs.pop();
                for(int j =0;j<r;j++)
                    str.top()+=snap;
                snap = str.top();
                str.pop();
            }
        }
        return snap;
    }
};

int main(){
    string str = "2[abc]3[cd]ef";
    Solution s;
    cout << s.decodeString(str)<<endl;
}
