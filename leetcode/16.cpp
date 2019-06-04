#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return {};

        sort(nums.begin(), nums.end());
        
        if (nums.size() <= 2 | nums.front() > 0 | nums.back() < 0) 
            return {};

        vector<vector<int>> rst;
        
        for(auto i=0;i<nums.size()-2;i++){
            if(nums[i] > 0)
                break;

            auto target = - nums[i];
            int j = i+1, k = nums.size()-1;
            
            while(j < k){
                if(nums[j]+ nums[k] == target){
                    rst.push_back({nums[i], nums[j], nums[k]});
                    while(nums[j] == nums[j+1] && j < k) j++;
                    while(nums[k-1] == nums[k-1] && j< k) k--;
                    j++;k--;
                }else if (nums[j] + nums[k] < target){
                    j++;
                }else k--;
            
            }
        
        }
        return rst;
    }
};


int main(){
    Solution s;

    vector<int> v{-1, 2, 1, -4};
    //std::ifstream is("solution15.txt");

    //string str;
    //vector<int> v;
    //while(std::getline(is, str,',')){
        //v.push_back(std::stoi(str));
    //}

    auto rst = s.threeSumClosest(v, 1);

    for(auto v: rst){
        cout << v[0] << ' ' << v[1] << ' '<< v[2] << endl;
    }


}
