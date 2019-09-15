//
// Created by ningyu on 2019/9/10.
//

#include "../common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if(abs(x - 1.0) < 1e-10)
            if(n%2==0)
                return 1;
            else
                return x;
        if(n == 0)
            return 1;
        bool pos = n > 0;
        uint64_t n1 = llabs(n);

        double last_pow = x;
        double ans=1;

        while(n1>0) {
            if((n1&1) != 0){
                ans *= last_pow;
            }
            n1 = n1 >> 1;
            last_pow *= last_pow;
        }

        return pos?ans:1/ans;
    }
};

int main(){

    Solution s;
    double x = 0.44894;
    int n = -5;
    cout << s.myPow(x, n) << endl;

}
