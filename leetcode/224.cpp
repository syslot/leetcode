#include "../common.h"
class Solution {
public:
    int calculate(string s) {
        if(s.length() ==0)
            return 0;
        stack<int> s_;
        s_.push(1);

        int sign=1;
        int num =0, ret=0;
        int i=0;
        while(i < s.length()){
            
            switch(s[i]){
                case '+':
                    sign=1;
                    i++;
                    break;
                case '-':
                    sign=-1;
                    i++;
                    break;
                case '(':
                    s_.push(sign*s_.top());
                    sign=1;
                    i++;
                    break;
                case ')':
                    s_.pop();
                    i++;
                    break;
                case ' ':
                    i++;
                    break;
                default:
                    num =0;
                    while(i<s.length() && '0'<=s[i] && '9'>= s[i]){
                        num = num * 10 + s[i] - '0';
                        i++;
                    }
                    ret += sign*num * s_.top();
            }
        }
        return ret;
    }
};

int main(){
    string str = "(1+(4+5+2)-3)+(6+8)";
    Solution s;
    cout << s.calculate(str) << endl;
}
