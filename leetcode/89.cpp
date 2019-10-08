#include "../common.h"

class Solution {
public:
    vector<int> grayCode(int n) {

        if(n <= 0)
            return vector<int> {0};
        if(n==1)
            return vector<int> {0,1};
        if(n>=2){
            auto sub = grayCode(n-1);

            vector<int> rst(sub.begin(), sub.end());

            int ext = pow(2, n-1);
            for(auto it = sub.rbegin(); it<sub.rend();it++){
                rst.push_back(*it + ext);
            }
            return rst;
            

        }
        
    }
};


int main(){
    Solution s;
    auto rst = s.grayCode(4);

    for(auto & w:rst)
        cout << w << " ";
    cout << endl;


}
