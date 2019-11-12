#include "../common.h"

class UnionSearch{
public:
    UnionSearch(int n){
        pre = new int[n];
        for(int i=0;i<n;i++)
            pre[i] = i;
    }
    
    int search(int x){
        int r=x;

        while(pre[r] != r){
            r=pre[r];
        }
        int i=x,j;
        while(i != r){
            j = pre[i];
            pre[i] = r;
            i = j;
        }
        return r;
    }

    void Union(int x, int y){

        int px = search(x);
        int py = search(y);
        pre[px] = py;
    }

    int *pre;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {

        int n = M.size();
        UnionSearch us(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(M[i][j] == 1)
                    us.Union(i,j);
            }
        int c=0;
        for(int i=0;i<n;i++){
            if(us.pre[i] == i)
                c++;
        }
        return c;    
    }
};

int main(){

    vector<vector<int>> M{
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    Solution s;
    cout << s.findCircleNum(M) << endl;


}
