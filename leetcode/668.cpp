#include "../common.h"

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if(k == 1 || k== m*n)
            return k;

        int l = 1, r=m*n+1;
        int mid=-1;
        while(l<r){
            mid = (l+r)>>1;
            
            int cnt = count(mid, m,n);
            if(cnt < k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return mid;

    }

    int count(int num, int m, int n){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt += min(num/i,n);
        }
        return cnt;
    }
};

int main(){
    int m =9,n=100,k=800;
    Solution s;
    cout << s.findKthNumber(m,n,k) << endl;
}
