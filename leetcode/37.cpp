//
// Created by syslot on 2019-08-20.
//

#include "../common.h"

using  namespace std;
class Solution {
public:

    int arr[9][9] = {0};

    void solveSudoku(vector<vector<char> >& board) {

        for(int i = 0; i<9; i++)
            for(int j = 0;j<9;j++)
                if(board[i][j] != '.')
                    arr[i][j] = board[i][j] - '0';

        int c,r;
        findNext(c,r);
        if(c == -1 || r == -1)
            return;

        DFS(c,r);
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                board[i][j] = arr[i][j] +'0';
        return;
    }

//    void printMat(int r, int c, int i){
//         cout<< r << " " << c << " : " << i << endl;
//          for(int i=0;i<9;i++){
//            for(int j=0;j<9;j++)
//                cout << arr[i][j];
//            cout << endl;
//          }
//    }

    bool DFS(int r,int c){
        // Get First Sq index
        int r_h = r / 3 * 3;
        int c_h = c / 3 * 3;
        int flags[10];
        for(int i = 1;i<=9;i++) {
            arr[r][c] = i;
//            printMat(r,c, i);
            int pass = true;
            // Check Sq
            memset(flags, 0, 10*sizeof(int));
            for(int idx = 0; idx < 9; idx ++)
            {
                int p = arr[r_h + idx / 3][c_h + idx % 3];
                if (p == 0)
                    continue;
                if(flags[p] == 0)
                    flags[p] = 1;
                else {
                    pass = false;
                    break;
                }
            }

            if(!pass)
                continue;

            // Check Row
            memset(flags, 0, 10 * sizeof(int));
            for(int idx = 0; idx < 9; idx++){
                int p = arr[r][idx];
                if(p == 0) continue;
                if(flags[p] == 0)
                    flags[p] = 1;
                else{
                    pass = false;
                    break;
                }
            }
            if(!pass)
                continue;

            // Check Col
            memset(flags, 0, 10*sizeof(int));
            for(int idx = 0;idx <9;idx++){
                int p = arr[idx][c];
                if(p == 0) continue;
                if(flags[p] == 0)
                    flags[p] = 1;
                else{
                    pass = false;
                    break;
                }
            }

            if(!pass)
                continue;

            int c_n, r_n;
            findNext(c_n, r_n);
            if (c_n == -1 && r_n == -1)
                return true;

            if(!DFS(c_n, r_n))
                continue;
            else
                return true;
        }
        arr[r][c] = 0;
        return false;

    }

    void findNext(int & c, int & r){
        c = r = -1;
        for(int i = 0;i< 9;i++)
            for(int j = 0; j< 9;j++){
                if(arr[i][j] == 0) {
                    c = i;
                    r = j;
                    return;
                }
            }
        return;
    }
};

int main(){

    vector<vector<char> > board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);

    for(auto w:board){
        for(auto c:w)
            cout << c;
        cout << endl;
    }



}