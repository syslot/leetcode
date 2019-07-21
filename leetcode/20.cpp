//
// Created by syslot on 21/07/19.
//
#include "../common.h"

class Solution {
public:
    bool isValid(string s) {
        char *stack_ = new char[s.length()];
        int top = 0;
        for(auto ch:s){
            if(top == 0 || !match(stack_[top-1], ch))
                stack_[top++] = ch;
            else
                top--;
        }

        if(top == 0)
            return true;
        else
            return false;


    }
    bool match(char a, char b){
        if(a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']')
            return true;
        return false;

    }
};

 int main(){

     Solution s;
     string str = "()[]{}";
     cout << str << ":" << s.isValid(str) << endl;


 }