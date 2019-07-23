//
// Created by syslot on 2019-07-23.
//

#include "../common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0){
            int p = ceil(abs(divisor) / abs(dividend));
            return divisor - p * dividend;
        }else{

        }

    }
};

int main(){

    cout << (-1*8) ;

}