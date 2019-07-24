//
// Created by syslot on 24/07/19.
//

#include "../common.h"


class Solution {
public:
    int longestValidParentheses(string s) {

        char *arr = new char[s.length()];

        int maxL = 0;
        int top = -1;

        int tmpL = 0;

        for (auto a:s) {
            if (top == -1) {
                arr[++top] = a;
//                tmpL++;
                continue;
            }

            if (arr[top] == '(' && a == '(') {
                arr[++top] = a;
//                tmpL ++;
            }else if(arr[top] == '(' && a == ')') {
                top --;
                tmpL +=2;
            }else{  // arr[tp[] == ')'
                top = -1;
                arr[++top] = a;
                if(tmpL >1 &&  tmpL > maxL)
                    maxL = tmpL %2 == 0 ?tmpL: tmpL-1;
                tmpL = 0;
            }
        }
        if(tmpL >1 &&  tmpL > maxL)
            maxL = tmpL %2 == 0 ?tmpL: tmpL-1;
        return maxL;
    }
};

int main(){

    Solution s;
    string str = ")()()()))))())()";
//    string str = "(()";

    cout << s.longestValidParentheses(str) << endl;

}