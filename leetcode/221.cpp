#include "../common.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        int c = INT_MIN;
        int n = matrix[0].size();
        int p[n];
        int cur[n];
        memset(p, 0, sizeof(p));
        memset(cur, 0, sizeof(cur));


        for(int i=0;i<n;i++){
            if(matrix[0][i] == '1'){
                p[i] = 1;
                if(p[i] > c)
                    c = p[i];
            }
        }

        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0] == '1')
                cur[0] = 1;
            else
                cur[0] = 0;
                if(cur[0] > c)
                    c = cur[0];
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    cur[j] = min(min(p[j-1], p[j]), cur[j-1])+1;
                    if(cur[j] > c)
                        c = cur[j];
                }else{
                    cur[j] = 0;
                }
            }
            memcpy(p, cur, sizeof(p));
        }
        if(c==INT_MIN)
            return 0;
        return c*c;
    }
};

int main(){
    //vector<vector<char>> mat{
        //{'1', '0', '1', '0', '0'},
        //{'1', '0', '1', '1', '1'},
        //{'1', '1', '1', '1', '1'},
        //{'1', '0', '0', '1', '0'}
    //};

    vector<vector<char>> mat{
    {'1','0','1','1','0','1'},
    {'1','1','1','1','1','1'},
    {'0','1','1','0','1','1'},
    {'1','1','1','0','1','0'},
    {'0','1','1','1','1','1'},
    {'1','1','0','1','1','1'}
};

    Solution s;
    cout << s.maximalSquare(mat) << endl;
    return 0;
}
