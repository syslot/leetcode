#include "../common.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int top[n];
        memset(top, 0, sizeof(top));

        while(k--){
            int idx =-1;
            for(int i=0;i<n;i++){
                if(idx == -1){
                    if(top[i] <n)
                        idx = i;
                    else 
                        continue;
                }
                if(matrix[idx][top[idx]] > matrix[i][top[i]])
                    idx = i;
            }
            if(k!=0)
                top[idx] ++;
            else
                return matrix[idx][top[idx]];
        }
    }

};

int main(){
    
    vector<vector<int>> mat{
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };

    Solution s;
    cout << s.kthSmallest(mat, 8) << endl;
}
