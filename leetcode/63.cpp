#include "../common.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m == 0 || n == 0)
            return 0;
        int path[obstacleGrid[0].size()];
        
        path[0]=obstacleGrid[0][0] == 0?1:0;
        for(int i=1;i<n;i++){
            path[i] = obstacleGrid[0][i]==0 && path[i-1] != 0 ?1:0;
        }

        for(int i=1;i<m;i++){
            path[0] = obstacleGrid[i][0] == 0 && path[0] !=0?path[0]:0;
            for(int j=1;j<n;j++){
                path[j] = obstacleGrid[i][j] == 0 ? path[j] + path[j-1]:0;
            }
        }
        return path[n-1];
    }
};

int main(){
        
    vector<vector<int>> grid{
  {0,0,0, 0},
  {0,1,0, 0},
  {0,0,0, 0}
};
    Solution s;
    cout << s.uniquePathsWithObstacles(grid) << endl;


}
