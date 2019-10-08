#include "../common.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        memset(visit, 0, sizeof(visit));
        helper(k,n, 1);
    }

    void helper(int k, int n, int begin){
        if(k == 0 && n == 0){
            vector<int> r;
            for(int i =1;i<=9;i++)
                if(visit[i])
                    r.push_back(i);
            rst.push_back(r);
        }


        for(int i = begin; i<=9;i++){
            if(visit[i]==0){
                visit[i] == 1;
                helper(k-1, n-i, i+1);
                visit[i] == 0;
            }
        }
    }

    int visit[10];
    vector<vector<int>> rst;
};


int main(){
    Solution s;
    auto rst = s.combinationSum3(3,7);

    for(auto & v:rst){
        for(auto & r:v){
            cout << r << " ";
        }
        cout << endl;
    }

}
