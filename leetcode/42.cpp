//
// Created by syslot on 2019-08-28.
//

#include "../common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        vector<tuple<int, int>> edge;
        if(height.size() == 0 || height.size() ==1)
            return 0;
//        map<int,int> edge;
        for(int i=0;i< height.size();i++){
            if(i==0 && height[0] > height[1] ||
                i==height.size()-1 && height[i] > height[i-1] ||
                i < height.size()-1 && i > 0 && height[i] > height[i+1] && height[i] > height[i-1]
                )
                edge.push_back(make_tuple(i,height[i]));
        }

        int sum = 0;
        if(edge.size()<=1)
            return sum;

        int left = 0;
        for(int i = 1;i < edge.size(); i++){
            auto e_b = get<0>(edge[left]);
            auto e_e = get<0> (edge[i]);
            auto h_b = get<1>(edge[left]);
            auto h_e = get<1>(edge[i]);

            auto h = min(h_b,h_e);
            sum += h * (e_e - e_b - 1);
            for(int j = e_b+1;j < e_e; j++){
                sum -= height[j];
            }
            left = i;
        }
    return sum;
    }
};

int main(){
    Solution s;


//    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << s.trap(height)<< endl;
}