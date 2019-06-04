#include "common.h"

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string s;
        for(int i =0;i<length;i++){
            if(str[i] != ' ')
                s+=str[i];
            else
                s+= "%20";
        }

        strcpy(str, s.c_str());
        return;
	}
};


int main(){
    Solution s;

    char str[16+1] = "we are happy";

    s.replaceSpace(str, strlen(str));

    cout << str << endl;

    
}
