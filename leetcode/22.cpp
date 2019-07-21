//
// Created by syslot on 21/07/19.
//

#include "../common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if( n == 0){
            return vector<string> {""};
        }

        if( n == 1 || n == 2){
            m.
            return 
        }


    }

    vector<string> p1(int n){
        auto it = m.find(n);
        if(it !=  m.end()){
            return  it->second;
        }

        if(n == 0){
            return vector<string> {""};
        }

        vector<string> a;
        auto old = generateParenthesis(n-1);
        for(auto str: old){
            a.push_back("()" + str);
            a.push_back(str+ "()");
            a.push_back("(" + str + ")");
        }

        set<string> ss(a.begin(), a.end());
        a.assign(ss.begin(), ss.end());

        return a;
    }

    map<int, vector<string>> m;


};

int main(){

    Solution s;
    auto rst = s.p1(4);

    for(auto str:rst){
        cout << str<<endl;
    }

}