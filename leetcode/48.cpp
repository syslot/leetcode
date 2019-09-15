//
// Created by ningyu on 2019/9/10.
//
#include "../common.h"

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        auto p = matrix;
        int s = matrix.size();
        for(int i = 0;i < s;i++)
            for(int j = 0;j<s;j++){
                matrix[j][s-i-1] = p[i][j];
            }
    }
};

int main(){
    vector<vector<int>> mat{{5, 1, 9,11},
                            {2, 4, 8,10},
                            {13, 3, 6, 7},
                            {15,14,12,16}};

    Solution s;
    s.rotate(mat);

    for(auto w:mat){
        for(auto i:w)
            cout << i << " ";
        cout << endl;
    }
}