#include "../common.h"

class Solution {
public:
    int scoreOfParentheses(string S) {
        if(S == "")
            return 0;
        if(S == "()")
            return 1;


        stack<char>st;

        int i=0, score = 0;
        while(i<S.length()){
            if(S[i]=='('){
                int c=0;
                int j=i+1;
                int tmp;
                while(j<S.length()){
                    if(S[j] == '(')
                        c++;
                    else if(S[j] == ')' && c==0){
                        tmp = scoreOfParentheses(S.substr(i+1, j-i-1));
                        break;
                    }else{
                        c--;
                    }
                    j++;
                }
                if(tmp)
                    score += tmp*2;
                else 
                    score += 1;
                i = j+1;
            }else
                i++;
        }
        return score;
        
    }
};

int main(){

    Solution s;
    string str = "(())()()";
    cout << s.scoreOfParentheses(str) << endl;

}
