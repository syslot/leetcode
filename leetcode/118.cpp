#include "../common.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rst;
        if(numRows == 0)
            return rst;
        if(numRows == 1){
            rst.push_back(vector<int>{1});
            return rst;
        }
            
        for(int i=0;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<i+1;j++){
                if(j==0 || j == i){
                    row.push_back(1);
                }else{
                    row.push_back(rst[i-1][j-1] + rst[i-1][j]);
                }
            }
            rst.push_back(row);
        }
        return rst;
    }
};

int main(){
    Solution s;
    auto  rst = s.generate(5);
    for(auto & row : rst){
        for(auto &v : row){
            cout << v << " ";
        }
        cout << endl;
    }
}
