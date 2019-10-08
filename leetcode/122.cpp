#include "../common.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        bool flag = 0;
        int small;
        for(int i =0;i<prices.size();i++){
            if(!flag){ // Find Small
                if( i == 0 || i > 0 && prices[i] < prices[i-1]){
                    if((i < prices.size()-1 && prices[i] > prices[i+1]))
                        continue;
                    small = prices[i];
                    flag = !flag;
                } 
            }else{
                if(i >0 && prices[i] > prices[i-1]){
                    if((i<prices.size()-1 && prices[i] < prices[i+1]))
                        continue;
                    p += prices[i] - small;
                    flag = !flag;
                    
                }
            }
        }
        return p;
    }
};

int main(){
    
    //vector<int> prices{2,2,5};
    vector<int> prices{1,2,3,4,5};
    Solution s ;
    cout << s.maxProfit(prices) << endl;

}
