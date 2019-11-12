#include "../common.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;

        this->word = word;
        m=board.size();
        n=board[0].size();
        visited = new bool *[m];
        for(int i=0;i<m;i++){
            visited[i] = new bool[n];
            memset(visited[i], 0, sizeof(bool) * n);
        };
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(dfs(board, i,j, 0))
                        return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, int x, int y, int depth){
        if(x<0 || x >=m)
            return false;
        if(y<0 || y >=n)
            return false;
        if(!visited[x][y] && board[x][y] == word[depth]){
            visited[x][y] = true;
            if(depth == word.size()-1)
                return true;
            if(dfs(board, x-1, y, depth+1) || dfs(board, x+1, y, depth+1) ||  dfs(board, x, y-1, depth+1) || dfs(board, x,y+1, depth+1))
                return true;
            visited[x][y] = false;
        }
        return false;
    }

    int m,n;

    bool **visited;
    string word;
};

int main(){

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    Solution s;
    cout << s.exist(board, "ABCB") << endl;
}
