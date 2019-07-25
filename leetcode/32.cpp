//
// Created by syslot on 24/07/19.
//

#include "../common.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() ==0)
            return 0;
        for(int i =0;i < s.length();i++){
            if(s[i] == ')'){
                if(i > 0 && s[i-1] == '(')
                    part[i] = 2;
                else
                    remind.insert(i);
            }
        }
        while(1){
            int c = combine();
            int m = merge(s);
            if(c== 0 && m == 0){
                break;
            }

        }
        int maxL = 0;
        for(auto& [key, value]: part){
            if(maxL < value)
                maxL = value;
        }
        return maxL;
    }

    int combine(){
        int counter = 0;
        for(auto it = part.crbegin(); it != part.crend(); it++)
            while( part.find(it->first - it->second) != part.end()){
                int tmpKey = it->first - it->second;
                part[it->first] +=  (part[tmpKey]);
                part.erase(tmpKey);
                counter++;
            }

        return counter;
    }

    int merge(string &s){
        int counter = 0;
        for(auto it = remind.cbegin(); it != remind.cend(); it++){
            int idx = *it -1;
            if(part.find(idx) != part.end() && idx - part[idx] >= 0 && s[idx - part[idx]] == '('){
                part[*it] = part[idx] + 2;
                part.erase(idx);
                counter ++;
            }
        }
        return counter;
    }

    map<int, int> part;
    set<int> remind;
};

int main(){

    Solution s;
//    string str = ")()()()))))())()";
//    string str = "()(()";
    string str = "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
    cout << s.longestValidParentheses(str) << endl;

}