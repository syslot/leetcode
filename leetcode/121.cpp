#include "../common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int min, max, rst = 0;
        min = max = prices[0];
        for(int i =1;i<prices.size();i++){
            if(prices[i] <= max && prices[i] >= min)
                continue;
            if(prices[i] < min){
                max = min = prices[i];
            }else{
                max = prices[i];
                if(max-min > rst){
                    rst = max-min;
                }
            }
        }
        
        
        return rst;
    }
};

int main(){
    vector<int> prices{7,6,5,4,3,2,1};
    Solution s;
    cout << s.maxProfit(prices)<<endl;


}
