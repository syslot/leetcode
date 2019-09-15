//
// Created by ningyu on 2019/9/9.
//

#include "../common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int * rst = new int[num1.length() + num2.length() + 3]();

        for(int i = 0; i< num1.length(); i++){
            for(int j = 0; j<num2.length(); j++){

                int c1 = num1[i] - '0';
                int c2 = num2[j] - '0';
                rst[i+j] += c1 * c2;
            }
        }

        for(int i = 0; i< num1.length() + num2.length() + 2; i++){
            if(rst[i] > 9) {
                rst[i+1] += rst[i]/10;
                rst[i] %= 10;
            }
        }
        reverse(rst, rst+num1.length()+ num2.length()+2);
        int i = 0;
        for(; rst[i] ==0 && i<num1.length()+num2.length()+2; i++);
        string s;
        s.reserve(1);
        for(;i<num1.length()+num2.length()+2;i++){
            s+= rst[i] + '0';
        }
        if(s.length() == 0)
            return string("0");
        return s;
    }
};

int main(){

    string num1 = "0";
    string num2 = "0";

    Solution s;
    cout << s.multiply(num1, num2) << endl;
    return 0;

}