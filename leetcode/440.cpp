#include "../common.h"

class Solution {
public:
    int findKthNumber(int up, int k) {
        int cur = 1;
        int pre = 1;
        while(cur < k){
            auto c = getCount(cur, up);
            if(cur + c > k){
                pre *= 10;
                cur ++;
            }else{
                pre++;
                cur += c;
            }

        }

        return pre;
    }

    int getCount(int n, int up){
        u_int64_t cur = n;
        u_int64_t next = cur+1;
        
        int count = 0;
        while(cur <= up){
            count += min(next, (u_int64_t)up+1) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }
};

int main(){

    int n = 140, k = 140;

    Solution s;
    cout << s.findKthNumber(n,k) << endl;


}
