#include "../common.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res=0;
        for(auto &v:grid)
            for(auto &p:v)
                if(p == 1)
                    res++;
        int loop = 0;
        while(true){
            int cur_res = res;
            stack<tuple<int,int>> s;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 2)
                        s.push(make_tuple(i,j));
                }
            }
            while(!s.empty()){
                int i = get<0>(s.top()), j = get<1>(s.top());
                s.pop();
                if(i>0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    cur_res --;
                }
                if(i<m-1 && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    cur_res --;
                }
                if(j>0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    cur_res --;
                }
                if(j<n-1 && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    cur_res --;
                }
            }
            loop++;
            if(cur_res == res)
                return -1;
            if(cur_res == 0)
                return loop;
            res = cur_res;
        }
        return 0;
    }
};


int main(){

    vector<vector<int>> grid{
        {2,0,1},
    };

    Solution s;
    cout << s.orangesRotting(grid) << endl;

}
