#include "../common.h"

class Solution {
public:
    string addStrings(string num1, string num2) {

        bool flag = false;

        string rst;
        int l = min(num1.length(), num2.length());
        int l1=num1.length()-1;
        int l2=num2.length()-1;
        while(l1>=0 && l2>=0){
            int tmp = num1[l1] -'0' + num2[l2] -'0';
            if(flag){
                tmp++;
                flag =false;
            }
            if(tmp >= 10){
                tmp -= 10;
                flag = true;
            }
            rst += tmp + '0';
            l1 --;
            l2 --;
        }

        if(num1.length() < num2.length()){
            for(int i=num2.length() - num1.length()-1;i>=0;i--){
                char tmp = num2[i];
                if(flag){
                    tmp++;
                    if(tmp > '9'){
                        tmp = '0';
                        flag = true;
                    }
                }
                rst += tmp;
            }
        }else{
            for(int i=num1.length() - num2.length()-1; i>=0 ; i--){
                char tmp = num1[i];
                if(flag){
                    tmp++;
                    if(tmp > '9'){
                        tmp = '0';
                        flag = true;
                    }
                }
                rst += tmp;
            }
        }

        if(flag)
            rst += '1';

        return string(rst.rbegin(), rst.rend());
        
    }
};

int main(){

    string num1= "1192938";
    string num2= "0";
    
    Solution s;
    auto rst = s.addStrings(num1, num2);

    cout << rst << endl;

}
