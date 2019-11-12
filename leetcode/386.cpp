#include "../common.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        limit = n;
        for(int i=1;i<=9;i++){
            dfs(i);
        }
        return rst;
    }

    void dfs(int tmp){
        if(tmp > limit)
            return ;
        
        rst.push_back(tmp);

        for(int i=0;i<10;i++){
            dfs(tmp*10+i);
        }
    }

    vector<int> rst;
    int limit;
};

int main(){

    Solution s;
    int n = 500000;
    auto rst = s.lexicalOrder(n);
    for(auto & v: rst){
        cout << v << " ";
    }
    cout << endl;
}
