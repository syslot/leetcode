#include "../common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int ix = matrix.size()-1;
        int iy = 0;

        while(ix >= 0 && iy < matrix[0].size()){
            if(matrix[ix][iy] == target)
                return true;
            else if(matrix[ix][iy] > target)
                ix--;
            else
                iy++;
        }
        return 0;
        
    }
};

int main(){

    vector<vector<int> > mat{
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    Solution s ;
    cout << s.searchMatrix(mat, 5) << endl;
}
