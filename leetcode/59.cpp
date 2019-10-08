//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rst(n, vector<int>(n));
        int x_m = n;
        int y_m = n;
        bool f[x_m][y_m];
        memset(f,0,sizeof(f));

        int order = 0;
        int idx=0, idy=0;
        int count = 1;

        while(true){
            if(order == 0){
                while(idy < y_m && !f[idx][idy] ){
                    f[idx][idy] = true;
                    rst[idx][idy] = count++;
                    idy++;
                }
                order += 1;
                idx += 1;
                idy --;
                if(idx >= x_m || f[idx][idy])
                    break;
            }
            if(order == 1){
                while(idx < x_m && !f[idx][idy]){
                    f[idx][idy] = true;
                    rst[idx][idy] = count++;
                    idx++;
                }
                order += 1;

                idy -= 1;
                idx --;
                if(idy < 0 || f[idx][idy])
                    break;

            }
            if(order == 2){
                while(idy >= 0 && !f[idx][idy]){
                    f[idx][idy] = true;
                    rst[idx][idy] = count++;
                    idy--;
                }
                order += 1;
                idx-=1;
                idy++;
                if(idx < 0 || f[idx][idy])
                    break;
            }
            if(order == 3){
                while(idx >=0 && !f[idx][idy]){
                    f[idx][idy] = true;
                    rst[idx][idy] = count++;
                    idx --;
                }
                order = 0;
                idy+=1;
                idx++;
                if(idy>=y_m|| f[idx][idy])
                    break;
            }

        }
        return rst;
    }
};

int main(){

    Solution s;
    auto v = s.generateMatrix(3);
    for(auto l:v){
        for(auto i:l)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;

}