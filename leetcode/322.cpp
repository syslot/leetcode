//
// Created by syslot on 2019/9/19.
//

#include "../common.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0)
            return -1;
        int inf = 100000000;

        int dp[amount+1];
        dp[0] = 0;

        for(int i =1;i<=amount;i++)
            dp[i]=inf;

        for(int i = 1;i<=coins.size();i++){
            for(int v=coins[i-1];v<=amount;v++ ){
                dp[v]=min(dp[v], dp[v-coins[i-1]]+1);
            }
        }

        if(dp[amount] == inf)
            return -1;
        else
            return dp[amount];
    }
};

int main(){


    vector<int> coins {1,2,5};
    int amount = 11;


    Solution s;
    cout << s.coinChange(coins, amount) << endl;
}
