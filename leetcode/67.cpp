#include "../common.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string rst;
        int t = min(a.length(), b.length());
        bool f = false;
        for(int i=0;i<t;i++){
            int cur = a[a.length() - i -1] - '0' + b[b.length() -i -1] - '0';
            if(f){
                cur ++;
                f = !f;
            }

            if(cur >= 2){
                cur -= 2;
                f = true;
            }
            rst += cur + '0';
        }
        if(a.length() == t && b.length() != t){
            for(int i = b.length() - t - 1; i>=0;i--){
                int cur = b[i] - '0';
                if(f){
                    cur ++;
                    f=!f;
                }
                if(cur >= 2){
                    cur -= 2;
                    f=true;
                }
                rst += cur + '0';
            }
        }else if(a.length() != t && b.length() == t){
            for(int i=a.length() - t -1;i>=0;i--){
                int cur = a[i] - '0';
                if(f){
                    cur ++;
                    f=!f;
                }
                if(cur >= 2){
                    cur -= 2;
                    f = true;
                }
                rst += cur +'0';
            }
        }

        if(f)
            rst += '1';
        
        return string(rst.rbegin(), rst.rend());
    }
};

int main(){

    Solution s;
    string a="11";
    string b="1";
    auto str = s.addBinary(a,b);
    cout << str << endl;

}
