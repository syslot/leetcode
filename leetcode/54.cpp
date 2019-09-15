//
// Created by ningyu on 2019/9/11.
//

#include "../common.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rst;
        if(matrix.size()==0 || matrix[0].size() == 0)
            return rst;
        int x_m = matrix.size();
        int y_m = matrix[0].size();
        bool f[x_m][y_m];
        memset(f,0,sizeof(f));
        rst.reserve(matrix.size() * matrix[0].size());

        int order = 0;
        int idx=0, idy=0;

        while(true){
            if(order == 0){
                while(idy < y_m && !f[idx][idy] ){
                    f[idx][idy] = true;
                    rst.push_back(matrix[idx][idy]);
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
                    rst.push_back(matrix[idx][idy]);
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
                    rst.push_back(matrix[idx][idy]);
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
                    rst.push_back(matrix[idx][idy]);
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
    vector<vector<int> > mat {{1,2,3},{4,5,6},{7,8,9}};//mat{{1,2,3,4},{5,6,7,8}, {9,10,11,12},{13,14,15,16}};

    Solution s;
    auto v = s.spiralOrder(mat);
    for(auto t:v){
        cout << t << " ";
    }
    cout << endl;

}