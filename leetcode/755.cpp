#include "../common.h"

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {

        while(V--){
            // left detect;
            bool flag=false;
            int i = K-1;
            int low = K;
            for(;i>=0;i--){
                if(heights[i] > heights[low])
                    break;
                else if(heights[i] < heights[low]){
                    flag = true;
                    low = i;
                }
            }
            if(flag){
                heights[low] ++;
                continue;
            }
            // right detect;
            i = K+1;
            low = K;
            for(;i<heights.size();i++){
                if(heights[i] > heights[low])
                    break;
                else if(heights[i] < heights[low]){
                    flag = true;
                    low =i;
                }
            }
            if(flag){
                heights[low] ++;
                continue;
            }

            // stay local;
            heights[K] ++;
        }
        return heights;
    }
};
int main(){

    vector<int> heights{1,2,3,4,3,2,1,2,3,4,3,2,1};
    int V = 10;
    int k = 2;

    Solution s;
    auto rst = s.pourWater(heights, V, k);

    for(auto& v: rst)
        cout << v << " ";
    cout << endl;

    return 0;
}
