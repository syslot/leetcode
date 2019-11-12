#include "../common.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        m = grid.size();
        n = grid[0].size();
        
        max_a=0;
        for(int i =0;i<m;i++)
        {
            vector<bool> row;
            for(int j=0;j<n;j++)
                row.push_back(false);
            visited.push_back(row);
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]){
                    area=0;
                    visit(i,j, grid);
                    if(area > max_a)
                        max_a = area;
                }

        return max_a;
    }

    void visit(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i >=m  || j < 0 || j>=n)
            return;

        if(visited[i][j] || grid[i][j] == 0)
            return;

        visited[i][j] = true;
        area++;
        visit(i+1,j,grid);
        visit(i-1,j,grid);
        visit(i,j-1,grid);
        visit(i,j+1,grid);
    }

    int m,n, area;
    vector<vector<bool>> visited;
    int max_a;
};

int main(){

    vector<vector<int>> grid{
        {0,0,1,0,0,0,0,1,0,0,0,0,0}
 //{0,0,0,0,0,0,0,1,1,1,0,0,0},
 //{0,1,1,0,1,0,0,0,0,0,0,0,0},
 //{0,1,0,0,1,1,0,0,1,0,1,0,0},
 //{0,1,0,0,1,1,0,0,1,1,1,0,0},
 //{0,0,0,0,0,0,0,0,0,0,1,0,0},
 //{0,0,0,0,0,0,0,1,1,1,0,0,0},
 //{0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;


}
