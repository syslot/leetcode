#include "../common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int value[n];

        for(int i =0;i<n;i++)
            value[i]=grid[0][i];
        for(int i=1;i<n;i++)
            value[i]+=value[i-1];

        for(int i =1;i<m;i++){
            value[0]  += grid[i][0];
            for(int j = 1;j<n;j++){
                value[j] = min(value[j], value[j-1])+grid[i][j];
            }
        }

        
        return value[n-1];

        
    }
};

int main(){
    vector<vector<int>> grid {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution s;
    cout << s.minPathSum(grid) <<endl;
}
