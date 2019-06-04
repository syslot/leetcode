//
// Created by syslot on 2019-01-23.
//


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        auto size = height.size();
        int max=-1;
        for(auto i=0;i< size;i++){
            for(auto j=0;j< size;j++){
                int p =  height[i] < height[j]? height[i] : height[j];
                auto tmp = p * abs(j-i);
                max = max > tmp ? max:tmp;
            }
        }
        return max;
    }
};

class Solution{
public:
    int maxArea(vector<int>& height){
        auto size = height.size();
        int max = -1;
        // if left > right
        //      flag = true
        bool flag = true;
        int i = 0, j = size - 1;
        while (i<j){
            if(height[i] < height[j])
                flag = false;
            else
                flag = true;
            int p;
            if (flag){
                p = height[j] * (j-i);
                j--;
            }else{
                p = height[i] *(j-i);
                i++;
            }
            max = max > p?max:p;
        }
        return max;
    }
};

int main(){
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution s = Solution();
    cout<< s.maxArea(height)<< endl;
}