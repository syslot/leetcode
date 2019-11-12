#include "../common.h"

class Solution {
public:
    int integerBreak(int n) {
        int a[n+1];
        memset(a, 0, sizeof(a));
        a[2] = 2;
        a[3] = 2;
        for(int i=4;i<=n;i++){
            a[i] = a[i-2]*2;
            for(int j=3;j<=i/2;j++){
                int tmp = a[i-j] * j;
                if(tmp > a[i])
                    a[i] = tmp;
            }

        }
        return a[n];
        
    }
};

int main(){
    Solution s;
    cout << s.integerBreak(58) << endl;
}
