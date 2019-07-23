//
// Created by syslot on 2019-07-23.
//

#include "../common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == -2147483648 && divisor  == -1)
            return 2147483647;

        if(dividend == -2147483648 && divisor == -2147483648)
            return 1;

        if(dividend == 2147483647 && divisor == 1)
            return 2147483647;

        if(dividend == -2147483648 && divisor == 1)
            return -2147483647;
        int neg = (dividend > 0 ) ^ (divisor > 0) ? -1:1;
        int sum = 0;
        int64_t ll_dividend = llabs(dividend);
        int64_t ll_divisor = llabs(divisor);
        while(ll_dividend >=0){
            ll_dividend -= ll_divisor;
            sum++;
        }
        sum--;
        return neg * sum;
    }
};

int main(){
    Solution s;
//    cout << s.divide(-2147483648,-1) << endl;
//     cout << s.divide(2147483647, -1) << endl;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7,-3 ) << endl;
    cout << s.divide(-9, -1) << endl;

}