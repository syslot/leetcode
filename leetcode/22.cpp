//
// Created by syslot on 21/07/19.
//

#include "../common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        track();
        return rst;
    }

    void track(string str = "", int left =0 , int right=0){

        if(str.length() == 2*n)
            rst.push_back(str);

        if(left < n){
            track(str+'(', left+1, right);
        }
        if(right < left){
            track(str+')', left,right+1);
        }

    }

    vector<string> rst;
    int n;

};

int main(){

    Solution s;
    auto rst = s.generateParenthesis(3);

    for(auto str:rst){
        cout << str<<endl;
    }

}