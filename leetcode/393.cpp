#include "../common.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.size()== 0)
            return true;

        int i=0;
        while(i<data.size()){
            int ret = checkHeadValid(data[i]);
            if(ret == 0){
                return false;
            }else{
                if(ret != 1){
                    bool valid = true;
                    for(int j=1;j<ret;j++){
                        if(i+j == data.size() || !checkFellowValid(data[i+j])){
                            valid = false;
                            break;
                        }
                    }
                    if(!valid){
                        return false;
                    }
                }
                i += ret;
            }
        }
        return true;

    }

    int checkHeadValid(int n){
        if(n<0x80)
            return 1;
        else if(n>>3 == 0x1E)
            return 4;
        else if(n>>4 == 0xE)
            return 3;
        else if(n>>5 == 0x6)
            return 2;
        //if(n < 0x80)
        //    return 1;
        //else if(n <= 223 && n >= 192)
        //    return 2;
        //else if(n >=208 && n <= 223)
        //    return 3;
        //else if(n>=240 && n <= 247)
        //    return 4;
        else 
            return 0;
    }

    int checkFellowValid(int n){
        if(n>=128 && n<=191){    
            return 1;
        }else 
            return 0;
    }
};

int main(){

    vector<int> data{230, 136, 145, 235,140,4};
    //vector<int> data{235, 140, 4};

    Solution s;
    cout << s.validUtf8(data)<< endl;

}
