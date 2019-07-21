//
// Created by syslot on 19/07/19.
//

#include "../common.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0){
            return vector<string>{};
        }
        char * d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        deque<string> rst;
        auto it = digits.end() -1;
        int ch  = (*it - '2');
//        int len = strlen(d[ch]);

        for(int i = 0 ;i<strlen(d[ch]);i++){
            rst.push_back(string(1,d[ch][i]));
        }
        if(digits.end() - digits.begin() == 1)
            return vector<string>{rst.begin(), rst.end()};
        for(auto it = digits.end()-2; it >= digits.begin(); it--){
            int ch = (*it - '2');
            int len = digits.end() - it-1;

            for(string str = rst.front();str.length() == len; rst.pop_front(), str = rst.front()){

                for (int i = 0; i < strlen(d[ch]); i++) {
                    rst.push_back(d[ch][i] + str);
                }
            }
        }
        return vector<string>{rst.begin(),rst.end()};
    }
};


int main(){
    string i = "";


    Solution s = Solution();

    auto rst = s.letterCombinations(i);

    for (auto v: rst){
        cout << v << endl;
    }
}